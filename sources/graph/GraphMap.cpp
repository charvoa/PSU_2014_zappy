//
// GraphMap.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:46 2015 Nicolas Girardot
// Last update Sat Jun 27 14:55:20 2015 Nicolas Girardot
//

#include "GameEngine.hh"
#include "GraphMap.hh"

GraphMap::GraphMap(int width, int height, SDL_Renderer *renderer)
{
  _locked = new Position(-1, -1);
  std::cout << "testouilleee1" << std::endl;
  _width = width;
  std::cout << "testouilleee2" << std::endl;
  _height = height;
  std::cout << "testouilleee3" << std::endl;
  _squareSize = 100;
  _grass = IMG_Load("grass.jpg");
  _grasst = SDL_CreateTextureFromSurface(renderer, _grass);
  _dirt = IMG_Load("dirt.jpg");
  _dirtt = SDL_CreateTextureFromSurface(renderer, _dirt);
  std::cout << "testouilleee4" << std::endl;
}

GraphMap::~GraphMap() {}

void	GraphMap::draw(SDL_Renderer *renderer, Position &pos, Position &focus, std::vector<std::vector<Case *> > map)
{
  (void) pos;
  int	i;
  int	j;
  for(i = focus._x - 3  ; i <= focus._x + 3 ; i++)
    {
      for (j = focus._y - 3 ; j <= focus._y + 3 ; j++)
	{
	  SDL_Rect rect;
	  rect.x = (150 + (i - focus._x + 3) * _squareSize);
	  rect.y = (150 + (j - focus._y + 3) * _squareSize);
	  rect.w = _squareSize - 1;
	  rect.h = _squareSize - 1;
	  if (j < 0 || i < 0 || j > _height - 1 || i > _width - 1);
	  else
	    {
	      if (map.at(j).at(i)->getType() == Case::GRASS)
		SDL_RenderCopy(renderer, _grasst, NULL, &rect);
	      else
		SDL_RenderCopy(renderer, _dirtt, NULL, &rect);
	    }
	}
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

void	GraphMap::setLocked(int x, int y)
{
  _locked->_x = x;
  _locked->_y = y;
}
