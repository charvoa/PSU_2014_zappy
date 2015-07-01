//
// GraphMap.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:46 2015 Nicolas Girardot
// Last update Wed Jul  1 13:53:06 2015 Nicolas Girardot
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
  _incant = IMG_Load("incantation1.png");
  _incantt = SDL_CreateTextureFromSurface(renderer, _incant);
  _playerSkin = IMG_Load("spriteGame.png");
  _playerSkint = SDL_CreateTextureFromSurface(renderer, _playerSkin);
  _egg = IMG_Load("egg.png");
  _eggt = SDL_CreateTextureFromSurface(renderer, _egg);
  _bubble = IMG_Load("bubble.png");
  _bubblet = SDL_CreateTextureFromSurface(renderer, _bubble);
}

GraphMap::~GraphMap() {}

void	GraphMap::draw(SDL_Renderer *renderer, Position &focus, std::vector<std::vector<Case *> > map, std::list<IACharacter *> &players, std::list<Egg *> &eggs)
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
  for(std::list<Egg *>::iterator it = eggs.begin(); it != eggs.end() ; it++)
    {
      if ((*it)->getX() >= focus._x - 3 && (*it)->getX() <= focus._x + 3 && (*it)->getY() >= focus._y - 3 && (*it)->getY() <= focus._y + 3)
	{
	  SDL_Rect rect;
	  rect.x = (175 + ((*it)->getX() - focus._x + 3) * _squareSize);
	  rect.y = (200 + ((*it)->getY() - focus._y + 3) * _squareSize);
	  rect.w = 50;
	  rect.h = 50;
	  SDL_RenderCopy(renderer, _eggt, NULL, &rect);
	}
    }
  for(std::list<IACharacter *>::iterator it = players.begin(); it != players.end() ; it++)
    {
      if ((*it)->getPosition()->_x >= focus._x - 3 && (*it)->getPosition()->_x <= focus._x + 3 && (*it)->getPosition()->_y >= focus._y - 3 && (*it)->getPosition()->_y <= focus._y + 3)
	{
	  SDL_Rect rect;
	  if ((*it)->isBroadcasting())
	    {
	      rect.x = (220 + ((*it)->getPosition()->_x - focus._x + 3) * _squareSize);
	      rect.y = (50 + ((*it)->getPosition()->_y - focus._y + 3) * _squareSize);
	      rect.w = 50;
	      rect.h = 50;
	      SDL_RenderCopy(renderer, _bubblet, NULL, &rect);
	      (*it)->updateBroadcast();
	    }
	  rect.x = (150 + ((*it)->getPosition()->_x - focus._x + 3) * _squareSize);
	  rect.y = (100 + ((*it)->getPosition()->_y - focus._y + 3) * _squareSize);
	  rect.w = 100;
	  rect.h = 142;
	  SDL_RenderCopy(renderer, _playerSkint, NULL, &rect);
	}
    }
  for(i = focus._x - 3  ; i <= focus._x + 3 ; i++)
    {
      for (j = focus._y - 3 ; j <= focus._y + 3 ; j++)
	{
	  if (j < 0 || i < 0 || j > _height - 1 || i > _width - 1);
	  else
	    {
	      if (map.at(j).at(i)->getIncant() == true)
		{
		  SDL_Rect rect;
		  rect.x = (100 + (i - focus._x + 3) * _squareSize);
		  rect.y = (100 + (j - focus._y + 3) * _squareSize);
		  rect.w = 200;
		  rect.h = 200;
		  SDL_RenderCopy(renderer, _incantt, NULL, &rect);
		}
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
