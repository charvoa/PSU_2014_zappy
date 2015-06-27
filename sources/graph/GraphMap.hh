//
// GraphMap.hh for Zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:33 2015 Nicolas Girardot
// Last update Fri Jun 26 16:31:42 2015 Nicolas Girardot
//

#ifndef GRAPHMAP_HH_
#define GRAPHMAP_HH_

#include "Position.hpp"
#include "Case.hh"
#include <SDL2/SDL_image.h>

class GameEngine;

class GraphMap
{
private:
  SDL_Surface *_grass;
  SDL_Texture *_grasst;
  SDL_Surface *_dirt;
  SDL_Texture *_dirtt;
  int	_height;
  int	_width;
  int	_squareSize;
  Position *_locked;
public:
  GraphMap(int, int, SDL_Renderer *);
  ~GraphMap();
  void	draw(SDL_Renderer *, Position &, Position &, std::vector<std::vector<Case *> >);
  void	setLocked(int, int);
  int	getHeight();
  int	getWidth();
};

#endif
