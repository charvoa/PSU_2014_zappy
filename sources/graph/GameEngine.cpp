//
// GameEngine.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Jun 22 17:36:22 2015 Nicolas Girardot
// Last update Tue Jun 23 14:06:37 2015 Nicolas Girardot
//

#include "GameEngine.hh"

GameEngine::GameEngine() {
  _gMap = NULL;
}

GameEngine::~GameEngine() {
  SDL_DestroyWindow(_window);
  SDL_Quit();
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

void	GameEngine::init_object()
{
  AObject	*map = new Map();

  if (map->initialize() == true)
    _object.push_back(map);
  //Ajouter les autres Object TODO
}

bool	GameEngine::initialize()
{
  _window = SDL_CreateWindow("Zappy - La Pintade 2015", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_SHOWN );
  if (!_window)
    std::cout << "Error on Windows Create" << std::endl;
  else
    _renderer = SDL_CreateRenderer(_window, 0, SDL_RENDERER_ACCELERATED);
  _socket->writeOnSocket("msz\n");
  return true;
}

bool	GameEngine::update()
{
  this->_socket->selectSocket();
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
  std::cout << "okokok" << std::endl;
  if (this)
    std::cout << "this is good" << std::endl;
  this->_gMap = new GraphMap(x, y);
  std::cout << "okokokabc" << std::endl;
}

void	GameEngine::draw()
{
  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255 );
  SDL_RenderClear(_renderer);
  if (_gMap != NULL)
    {
      std::cout << " != NULL" << std::endl;
      _gMap->draw(_renderer);
    }
  SDL_RenderPresent(_renderer);
}

void	GameEngine::run()
{
  this->_socket = new Socket("127.0.0.1", 4242, this);
  initialize();
  while (this->update())
    draw();
}
