//
// GraphMap.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:46 2015 Nicolas Girardot
// Last update Thu Jun 25 18:45:40 2015 Nicolas Girardot
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
	      SDL_SetRenderDrawColor(renderer, 150, 0, 0, 255);
	  else if ((pos._x == (i - 1)) && (pos._y == (j - 1)))
	    SDL_SetRenderDrawColor(renderer, 150, 255, 150, 255);
	  else
	    SDL_SetRenderDrawColor(renderer, 0, 150, 0, 100);
	  SDL_RenderFillRect(renderer, &rect);
	}
      j = 1;
    }
}

int	GraphMap::getWidth()
{
  return _width;
}

int	GraphMap::getHeight()
{
  return _height;
}

void	GraphMap::setLocked(Position &pos)
{
  _locked->_x = pos._x;
  _locked->_y = pos._y;
}
