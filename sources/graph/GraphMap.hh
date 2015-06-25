//
// GraphMap.hh for Zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:33 2015 Nicolas Girardot
// Last update Thu Jun 25 16:55:15 2015 Nicolas Girardot
//

#ifndef GRAPHMAP_HH_
#define GRAPHMAP_HH_

#include "Position.hpp"

class GameEngine;

class GraphMap
{
private:
  int	_height;
  int	_width;
  int	_squareSize;
  Position *_locked;
public:
  GraphMap(int, int);
  ~GraphMap();
  void	draw(SDL_Renderer *, Position &);
  void	setLocked(Position &);
  int	getHeight();
  int	getWidth();
};

#endif
