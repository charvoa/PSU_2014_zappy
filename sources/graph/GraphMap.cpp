//
// GraphMap.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:46 2015 Nicolas Girardot
// Last update Thu Jun 25 12:06:27 2015 Nicolas Charvoz
//

#include "GameEngine.hh"
#include "GraphMap.hh"

GraphMap::GraphMap(int width, int height)
{
  _locked = new Position(-1, -1);
  std::cout << "testouilleee1" << std::endl;
  _width = width;
  std::cout << "testouilleee2" << std::endl;
  _height = height;
  std::cout << "testouilleee3" << std::endl;
  _squareSize = 700 / width;
  std::cout << "testouilleee4" << std::endl;
}

GraphMap::~GraphMap() {}

void	GraphMap::draw(SDL_Renderer *renderer, Position &pos)
{
  int	i;
  int	j;
  for(i = 1 ; i <= _width ; i++)
    {
      for (j = 1 ; j <= _height ; j++)
	{
	  SDL_Rect rect;
	  rect.x = 150 + ((i - 1) * _squareSize);
	  rect.y = 150 + ((j - 1) * _squareSize);
	  rect.w = _squareSize - 1;
	  rect.h = _squareSize - 1;
	  if (i - 1 == _locked->_x && j - 1 == _locked->_y)
	      SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	  else if ((pos._x == (i - 1)) && (pos._y == (j - 1)))
	    SDL_SetRenderDrawColor(renderer, 150, 255, 150, 255);
	  else
	    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 100);
	  SDL_RenderFillRect(renderer, &rect);
	}
      j = 1;
    }
}

void	GraphMap::setLocked(int a, int b)
{
  std::cout << "send data" << std::endl;
  _locked->_x = a;
  std::cout << "data " << a << " :: " << _locked->_x << std::endl;
  _locked->_y = b;
}
