//
// GameEngine.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Jun 22 17:36:22 2015 Nicolas Girardot
// Last update Wed Jun 24 15:12:21 2015 Nicolas Girardot
//

#include "GameEngine.hh"

GameEngine::GameEngine() {
  _gMap = NULL;
}

GameEngine::~GameEngine() {
  SDL_DestroyWindow(_window);
  SDL_Quit();
  TTF_Quit();
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
  TTF_Init();
  _mousePos = Position(10, 10);
  _hud = new HUD(_renderer);
  _socket->writeOnSocket("msz\n");
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
  if (this)
    _gMap = new GraphMap(x, y);
}

void	GameEngine::setLocked()
{
  int	a;
  int	b;
  SDL_GetMouseState(&a, &b);
  std::cout << "click" << std::endl;
  _gMap->setLocked((a - 150) / 35, (b - 150) / 35);
}

void	GameEngine::getMousePos()
{
  int	a;
  int	b;
  SDL_GetMouseState(&a, &b);
  if ((a - 150) / 35 == _mousePos._x && (b - 150) / 35 == _mousePos._y);
  else
    {
      std::cout << "test" << std::endl;
      Position current((a - 150) / 35, (b - 150) / 35);
      _mousePos = current;
      _hud->updateCase(_mousePos);
    }
}

void	GameEngine::setCase(std::vector<std::string> &content)
{
  std::vector<int> tab;

  tab.push_back(stoi(content.at(2)));
  tab.push_back(stoi(content.at(3)));
  tab.push_back(stoi(content.at(4)));
  tab.push_back(stoi(content.at(5)));
  tab.push_back(stoi(content.at(6)));
  tab.push_back(stoi(content.at(7)));
  tab.push_back(stoi(content.at(8)));
  _cases.insert(std::pair<Position*, std::vector<int>&>(new Position(stoi(content.at(0)), stoi(content.at(1))), tab));
}

void	GameEngine::draw()
{
  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
  SDL_RenderClear(_renderer);
  if (_gMap != NULL)
    _gMap->draw(_renderer, _mousePos);
  _hud->draw(_renderer);
  SDL_RenderPresent(_renderer);
}

void	GameEngine::run()
{
  this->_socket = new Socket("127.0.0.1", 4242, this);
  initialize();
  while (this->update())
    draw();
}
