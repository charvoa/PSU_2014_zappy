//
// Game.hh for Zappy in /home/florian/rendu/SystemeUnix/PSU_2014_zappy/sources/graph
//
// Made by Florian PERU
// Login   <florian@epitech.eu>
//
// Started on  Wed May  6 15:12:05 2015 Florian PERU
// Last update Thu Jun 25 16:49:16 2015 Serge Heitzler
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
#include <SDL2/SDL_ttf.h>
#include <SDL.h>
#include <Texture.hh>
#include <Model.hh>
#include "Socket.hh"
#include "Map.hpp"
#include "GraphMap.hh"
#include "Case.hh"
#include "Position.hpp"
#include "HUD.hh"

class Socket;

class	GameEngine : public gdl::Game
{
private:
  SDL_Window	*_window;
  SDL_Event	_event;
  SDL_Surface	*_surface;
  SDL_Renderer	*_renderer;
  Position	_mousePos;
  Socket	*_socket;
  GraphMap	*_gMap;
  HUD		*_hud;
public:
  GameEngine();
  ~GameEngine();
  SDL_Renderer &getRenderer();
  SDL_Window &getWindow();
  SDL_Surface &getSurface();
  void	init_object();
  bool	initialize();
  bool	update();
  void	getMousePos();
  void	createMap(std::vector<std::string> &);
  void	setCase(std::vector<std::string> &);
  void	setLocked();
  void	draw();
  void	run();
  bool		isClickedOnMap(int, int);
  Position	&determinePosClicked(std::pair<int,int> &, int, int);
  Position	&determinePosClickedOnGUI(int, int);
private:
  std::map<Position *, Case&> _cases;
};

#endif
