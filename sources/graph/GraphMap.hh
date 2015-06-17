//
// GraphMap.hh for Zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:33 2015 Nicolas Girardot
// Last update Mon Jun 22 15:22:13 2015 Nicolas Girardot
//

#ifndef GRAPHMAP_HH_
#define GRAPHMAP_HH_

class GameEngine;

class GraphMap
{
private:
  int	_height;
  int	_width;
  int	_squareSize;
public:
  GraphMap(int, int);
  ~GraphMap();
  void	draw(SDL_Renderer *);
};

#endif
