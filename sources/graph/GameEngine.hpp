//
// Game.hh for Zappy in /home/florian/rendu/SystemeUnix/PSU_2014_zappy/sources/graph
//
// Made by Florian PERU
// Login   <florian@epitech.eu>
//
// Started on  Wed May  6 15:12:05 2015 Florian PERU
// Last update Fri Jun 19 15:42:58 2015 Nicolas Girardot
//

#ifndef _GAMEENGINE_HPP_
#define _GAMEENGINE_HPP_

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <SDL/SDL.h>
#include <SDL.h>
#include <Texture.hh>
#include <Model.hh>
#include "Map.hpp"
#include "Socket.hh"

class	GameEngine : public gdl::Game
{
private:
  SDL_Window	*_window;
  SDL_Surface	*_surface;
  SDL_Event	_event;
  Socket	*_socket;
public:
  GameEngine() {}
  ~GameEngine() {
    SDL_DestroyWindow(_window);
    SDL_Quit();
  }

  void	init_object()
  {
    AObject	*map = new Map();

    if (map->initialize() == true)
      _object.push_back(map);
    //Ajouter les autres Object TODO
  }

  bool	initialize()
  {
    _window = SDL_CreateWindow("Zappy - La Pintade 2015", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_SHOWN );
    if (!_window)
      std::cout << "Error on Windows Create" << std::endl;
    else
      {
	_surface = SDL_GetWindowSurface(_window);
	SDL_FillRect(_surface, NULL, SDL_MapRGB(_surface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(_window);
      }
    return true;
  }

  bool	update()
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

  void	draw()
  {
    for (size_t i = 0; i < _object.size(); i++);
    //_object[i]->draw(_shader, _clock);

    //    _context.flush();
  }

  void	run()
  {
    this->_socket = new Socket("127.0.0.1", 4242);
    initialize();
    while (this->update());
  }

private:
  std::vector<AObject *>	_object;
};

#endif
