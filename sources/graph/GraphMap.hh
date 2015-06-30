//
// GraphMap.hh for Zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:33 2015 Nicolas Girardot
// Last update Thu Jul  2 11:23:09 2015 Nicolas Girardot
//

#ifndef GRAPHMAP_HH_
#define GRAPHMAP_HH_

#include "Position.hpp"
#include "Case.hh"
#include "Egg.hh"
#include <SDL2/SDL_image.h>
#include <list>
#include <iterator>
#include <iostream>
#include <sstream>

class GameEngine;

class GraphMap
{
private:
  SDL_Surface *_grass;
  SDL_Texture *_grasst;

  SDL_Surface *_playerSkin;
  SDL_Texture *_playerSkint;

  SDL_Surface *_dirt;
  SDL_Texture *_dirtt;

  SDL_Surface *_incant;
  SDL_Texture *_incantt;

  SDL_Surface *_egg;
  SDL_Texture *_eggt;

  SDL_Surface *_bubble;
  SDL_Texture *_bubblet;

  SDL_Surface *_food;
  SDL_Texture *_foodt;

  SDL_Surface *_rock1;
  SDL_Texture *_rock1t;

  SDL_Surface *_rock2;
  SDL_Texture *_rock2t;

  SDL_Surface *_rock3;
  SDL_Texture *_rock3t;

  SDL_Surface *_rock4;
  SDL_Texture *_rock4t;

  SDL_Surface *_rock5;
  SDL_Texture *_rock5t;

  SDL_Surface *_rock6;
  SDL_Texture *_rock6t;

  std::vector<std::vector<SDL_Texture *> > _sprites;

  int	_height;
  int	_width;
  int	_squareSize;
  Position *_locked;
public:
  GraphMap(int, int, SDL_Renderer *);
  ~GraphMap();
  void	draw(SDL_Renderer *, Position &, std::vector<std::vector<Case *> >, std::list<IACharacter *> &, std::list<Egg *>&);
  void	setLocked(int, int);
  int	getHeight();
  int	getWidth();
  void	initSprites(SDL_Renderer *);
};

#endif
