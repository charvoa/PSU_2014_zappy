//
// GameEngine.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Jun 22 17:36:22 2015 Nicolas Girardot
// Last update Thu Jun 25 20:08:35 2015 Nicolas Girardot
//

#include "GameEngine.hh"
#include <SDL/SDL_image.h>

GameEngine::GameEngine() {
  _gMap = NULL;
}

GameEngine::~GameEngine() {
  SDL_DestroyWindow(_window);
  SDL_Quit();
  TTF_Quit();
  IMG_Quit();
  _socket->closeSocket();
}

SDL_Renderer &GameEngine::getRenderer()
{
  return (*_renderer);
}

SDL_Window &GameEngine::getWindow()
{
  return (*_window);
}

SDL_Surface &GameEngine::getSurface()
{
  return (*_surface);
}


bool	GameEngine::initialize()
{
  _window = SDL_CreateWindow("Zappy - La Pintade 2015", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_SHOWN );
  if (!_window)
    std::cout << "Error on Windows Create" << std::endl;
  else
    _renderer = SDL_CreateRenderer(_window, 0, SDL_RENDERER_ACCELERATED);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();
  _mousePos = Position(10, 10);
  _hud = new HUD(_renderer);
  _socket->writeOnSocket("msz\r\n");
  return true;
}

bool	GameEngine::update()
{
  this->_socket->selectSocket();
  _hud->update();
  getMousePos();
  while (SDL_PollEvent(&_event))
    {
      if (_event.type == SDL_KEYDOWN)
	{
	  switch(_event.key.keysym.sym)
	    {
	    case SDLK_ESCAPE:
	      return false;
	      break;
	    default:
	      break;
	    }
	}
      if (_event.type == SDL_MOUSEBUTTONDOWN)
	{
	  if (_event.button.button == SDL_BUTTON_LEFT)
	    setLocked();
	}
      if (_event.type == SDL_QUIT)
	return false;
    }
  return true;
}

void	GameEngine::createMap(std::vector<std::string> &parse)
{
  int	x;
  int	y;
  std::string strx;
  std::string stry;

  strx = parse.at(0);
  stry = parse.at(1);
  x = stoi(strx);
  y = stoi(stry);
  std::cout << "MAP IS x = " << x << "::: Y = " << y << std::endl;
  if (this)
    _gMap = new GraphMap(x, y);
}

void	GameEngine::setLocked()
{
  int	a;
  int	b;
  SDL_GetMouseState(&a, &b);
  std::cout << "click" << std::endl;
  Position pos(a, b);
  std::pair<int, int> pair(6, 6);
  if (isEventOnMap(a, b) == true)
    {
      _hud->updateLocked(determinePosClicked(pair, a, b));
      _gMap->setLocked(determinePosClickedOnGUI(a, b));
    }
}

void	GameEngine::getMousePos()
{
  int	a;
  int	b;
  SDL_GetMouseState(&a, &b);
  if ((a - 150) / 100 == _mousePos._x && (b - 150) / 100 == _mousePos._y);
  else
    {
      std::cout << "test" << std::endl;
        if (isEventOnMap(a, b) == true)
	  {
	    Position current((a - 150) / 100, (b - 150) / 100);
	    _mousePos = current;
	    _hud->updateCase(_mousePos);
	  }
    }
}

void	GameEngine::setCase(std::vector<std::string> &content)
{
  Case new_case(stoi(content.at(3)),
  		stoi(content.at(4)),
  		stoi(content.at(5)),
  		stoi(content.at(6)),
  		stoi(content.at(7)),
  		stoi(content.at(8)),
  		stoi(content.at(2)));
  if (_cases[std::pair<int, int>(stoi(content.at(0)), stoi(content.at(1)))] != NULL)
    _cases[std::pair<int, int>(stoi(content.at(0)), stoi(content.at(1)))].setAll(stoi(content.at(3)),
										 stoi(content.at(4)),
										 stoi(content.at(5)),
										 stoi(content.at(6)),
										 stoi(content.at(7)),
										 stoi(content.at(8)),
										 stoi(content.at(2)));
  else
    _cases.insert(std::pair<std::pair<int, int>, Case *>(std::pair<int, int>(stoi(content.at(0)), stoi(content.at(1))), &new_case));

}

void	GameEngine::draw()
{
  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
  SDL_RenderClear(_renderer);
  _hud->draw(_renderer);
  if (_gMap != NULL)
    _gMap->draw(_renderer, _mousePos);
  SDL_RenderPresent(_renderer);
}

void	GameEngine::run()
{
  this->_socket = new Socket("127.0.0.1", 4242, this);
  _socket->writeOnSocket("GRAPHIC\n");
  initialize();
  while (this->update())
    draw();
}

bool		GameEngine::isEventOnMap(int xClick, int yClick)
{
  if (xClick < 150 || yClick < 150 || xClick > 850 || yClick > 850)
    return false;
  return true;
}

Position	&GameEngine::determinePosClicked(std::pair<int,int> & center, int xClick, int yClick)
{
  int x;
  int y;
  int posX;
  int posY;

  posX = (xClick - 150) / (700 / 7);
  posY = (yClick - 150) / (700 / 7);
  x = (center.first - 6 + posX) % _gMap->getWidth();
  y = (center.second - 6 + posY) % _gMap->getHeight();
  if (x < 0)
    x = _gMap->getWidth() + x;
  if (y < 0)
    y = _gMap->getHeight() + y;

  Position pos(x, y);
  return (pos);
}

Position	&GameEngine::determinePosClickedOnGUI(int xClick, int yClick)
{
  int posX;
  int posY;
  posX = (xClick - 150) / (700 / 7);
  posY = (yClick - 150) / (700 / 7);
  Position pos(posX, posY);
  return (pos);
}
