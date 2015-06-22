//
// Game.hh for Zappy in /home/florian/rendu/SystemeUnix/PSU_2014_zappy/sources/graph
//
// Made by Florian PERU
// Login   <florian@epitech.eu>
//
// Started on  Wed May  6 15:12:05 2015 Florian PERU
// Last update Mon Jun 22 15:20:38 2015 Nicolas Girardot
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
#include "GraphMap.hh"

class	GameEngine : public gdl::Game
{
private:
  SDL_Window	*_window;
  SDL_Event	_event;
  SDL_Surface	*_surface;
  SDL_Renderer	*_renderer;
  Socket	*_socket;
  GraphMap	*_gMap;
public:
  GameEngine() {}
  ~GameEngine() {
    SDL_DestroyWindow(_window);
    SDL_Quit();
  }

  SDL_Renderer &getRenderer()
  {
    return (*_renderer);
  }

  SDL_Window &getWindow()
  {
    return (*_window);
  }

  SDL_Surface &getSurface()
  {
    return (*_surface);
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
	_renderer = SDL_CreateRenderer(_window, 0, SDL_RENDERER_ACCELERATED);
      }
    _gMap = new GraphMap(10, 10);
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
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255 );
    SDL_RenderClear(_renderer);
    _gMap->draw(_renderer);
    SDL_RenderPresent(_renderer);
  }

  void	run()
  {
    this->_socket = new Socket("127.0.0.1", 4242);
    initialize();
    while (this->update())
      draw();
  }

private:
  std::vector<AObject *>	_object;
};

#endif
