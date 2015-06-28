//
// GraphMap.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:46 2015 Nicolas Girardot
// Last update Sat Jun 27 18:25:54 2015 Nicolas Girardot
//

#include "GameEngine.hh"
#include "GraphMap.hh"

GraphMap::GraphMap(int width, int height, SDL_Renderer *renderer)
{
  _locked = new Position(-1, -1);
  _width = width;
  _height = height;
  _squareSize = 100;
  _grass = IMG_Load("grass.jpg");
  _grasst = SDL_CreateTextureFromSurface(renderer, _grass);
  _dirt = IMG_Load("dirt.jpg");
  _dirtt = SDL_CreateTextureFromSurface(renderer, _dirt);
  _playerSkin = IMG_Load("spriteGame.png");
  _playerSkint = SDL_CreateTextureFromSurface(renderer, _playerSkin);

}

GraphMap::~GraphMap() {}

void	GraphMap::draw(SDL_Renderer *renderer, Position &focus, std::vector<std::vector<Case *> > map, std::list<IACharacter *> &players)
{
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
    for(std::list<IACharacter *>::iterator it = players.begin(); it != players.end() ; it++)
    {
      std::cout << "Player is being drawn at " << (*it)->_position->_x << "/" << (*it)->_position->_y << std::endl;
      if ((*it)->_position->_x >= focus._x - 3 && (*it)->_position->_x <= focus._x + 3 && (*it)->_position->_y >= focus._y - 3 && (*it)->_position->_y <= focus._y + 3)
	{
	  std::cout << "OLE" << std::endl;
	  SDL_Rect rect;
	  rect.x = (150 + ((*it)->_position->_x - focus._x + 3) * _squareSize);
	  rect.y = (100 + ((*it)->_position->_y - focus._y + 3) * _squareSize);
	  rect.w = 100;
	  rect.h = 142;
	  SDL_RenderCopy(renderer, _playerSkint, NULL, &rect);
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
