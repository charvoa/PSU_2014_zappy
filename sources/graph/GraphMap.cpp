//
// GraphMap.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:46 2015 Nicolas Girardot
// Last update Mon Jun 22 15:20:50 2015 Nicolas Girardot
//

#include "GameEngine.hpp"
#include "GraphMap.hh"

GraphMap::GraphMap(int width, int height)
{
  _width = width;
  _height = height;
  _squareSize = 1000 / width;
}

GraphMap::~GraphMap() {}

void	GraphMap::draw(SDL_Renderer *renderer)
{
  int	i;
  int	j;
  for(i = 1 ; i <= _width ; i++)
    {
      for (j = 1 ; j <= _height ; j++)
	{
	  SDL_Rect rect;
	  rect.x = ((i - 1) * _squareSize);
	  rect.y = ((j - 1) * _squareSize);
	  rect.w = _squareSize - 1;
	  rect.h = _squareSize - 1;
	  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	  SDL_RenderFillRect(renderer, &rect);
	}
      j = 1;
    }
}
