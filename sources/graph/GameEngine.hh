//
// Game.hh for Zappy in /home/florian/rendu/SystemeUnix/PSU_2014_zappy/sources/graph
//
// Made by Florian PERU
// Login   <florian@epitech.eu>
//
// Started on  Wed May  6 15:12:05 2015 Florian PERU
// Last update Sat Jul  4 23:51:27 2015 Nicolas Girardot
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
#include "Egg.hh"
#include "HUD.hh"
#include "./Sound/SoundManager.hh"
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
  Position	_focus;
  GraphMap	*_gMap;
  HUD		*_hud;
  int		_speed;
  int		_idFocus = -1;
public:
  GameEngine();
  ~GameEngine();
  SDL_Renderer &getRenderer();
  SDL_Window &getWindow();
  SDL_Surface &getSurface();
  void	addIncant(int, int);
  void	endIncant(std::vector<int> &);
  void	addPlayer(std::vector<int> &, std::string &);
  void	init_object();
  bool	initialize();
  void	deleteEgg(int, int);
  void	updatePlayer(std::vector<int> &);
  void	broadcast(std::tuple<int, std::string> &);
  bool	update();
  void	getMousePos();
  void	createMap(std::vector<std::string> &);
  void	setCase(std::vector<std::string> &);
  void	setLocked();
  void	draw();
  void	addEgg(std::vector<int> &);
  void	updateInventory(std::vector<int>&);
  void	deletePlayer(int);
  void	updateLvl(int, int);
  void	updateTime(int);
  void	run(const char *, int  );
  bool		isEventOnMap(int, int);
  void	updateTeamInfo(std::string &, int, int);
  void	getSpeed(int);
  void	endGame(std::string &);
  std::pair <int, int>determinePosClicked(std::pair<int,int> &, int, int);
  std::pair <int, int>determinePosClickedOnGUI(int, int);
private:
  static Sound&	_sound;
  std::vector<std::vector<Case*> > _cases;
  std::list<IACharacter *> _players;
  std::list<Egg *>		_eggs;
};

#endif
