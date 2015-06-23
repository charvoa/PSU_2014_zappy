//
// Game.hh for Zappy in /home/florian/rendu/SystemeUnix/PSU_2014_zappy/sources/graph
//
// Made by Florian PERU
// Login   <florian@epitech.eu>
//
// Started on  Wed May  6 15:12:05 2015 Florian PERU
// Last update Mon Jun 22 17:43:25 2015 Nicolas Girardot
//

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

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
#include "Socket.hh"
#include "Map.hpp"
#include "GraphMap.hh"

class Socket;

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
  GameEngine();
  ~GameEngine();
  SDL_Renderer &getRenderer();
  SDL_Window &getWindow();
  SDL_Surface &getSurface();
  void	init_object();
  bool	initialize();
  bool	update();
  void	createMap(std::vector<std::string> &parse);
  void	draw();
  void	run();
private:
  std::vector<AObject *>	_object;
};

#endif