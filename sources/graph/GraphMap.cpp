//
// GraphMap.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:46 2015 Nicolas Girardot
// Last update Tue Jun 23 12:08:03 2015 Nicolas Girardot
//

#include "GameEngine.hh"
#include "GraphMap.hh"

GraphMap::GraphMap(int width, int height)
{
  std::cout << "testouilleee1" << std::endl;
  _width = width;
  std::cout << "testouilleee2" << std::endl;
  _height = height;
  std::cout << "testouilleee3" << std::endl;
  _squareSize = 1000 / width;
  std::cout << "testouilleee4" << std::endl;
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
