//
// GraphMap.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Jun 19 17:00:46 2015 Nicolas Girardot
// Last update Sat Jul  4 13:44:21 2015 Nicolas Girardot
//

#include "GameEngine.hh"
#include "GraphMap.hh"

GraphMap::GraphMap(int width, int height, SDL_Renderer *renderer)
{
  _locked = new Position(-1, -1);
  _width = width;
  _height = height;
  _squareSize = 100;
  initSprites(renderer);
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
  _food = IMG_Load("gems/food.png");
  _foodt = SDL_CreateTextureFromSurface(renderer, _food);
  _rock1 = IMG_Load("gems/rock1.png");
  _rock1t = SDL_CreateTextureFromSurface(renderer, _rock1);
  _rock2 = IMG_Load("gems/rock2.png");
  _rock2t = SDL_CreateTextureFromSurface(renderer, _rock2);
  _rock3 = IMG_Load("gems/rock3.png");
  _rock3t = SDL_CreateTextureFromSurface(renderer, _rock3);
  _rock4 = IMG_Load("gems/rock4.png");
  _rock4t = SDL_CreateTextureFromSurface(renderer, _rock4);
  _rock5 = IMG_Load("gems/rock5.png");
  _rock5t = SDL_CreateTextureFromSurface(renderer, _rock5);
  _rock6 = IMG_Load("gems/rock6.png");
  _rock6t = SDL_CreateTextureFromSurface(renderer, _rock6);
}

GraphMap::~GraphMap() {}

void	GraphMap::initSprites(SDL_Renderer *renderer)
{
  std::stringstream	ss;
  std::vector<SDL_Texture *> tmp;
  for (int i = 1; i <= 8; i++)
    {
      tmp.clear();
      for (int j = 1; j <=4; j++)
	{
	  SDL_Surface *surface;
	  SDL_Texture *texture;
	  ss.str("");
	  ss.clear();
	  ss << "zelda_sprites/" <<  i << "-" << j << ".png";
	  surface = IMG_Load(ss.str().c_str());
	  texture = SDL_CreateTextureFromSurface(renderer, surface);
	  tmp.push_back(texture);
	}
      _sprites.push_back(tmp);
    }
}

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
	  if (j < 0 || i < 0 || j > _height - 1 || i > _width - 1);
	  else
	    {
	      rect.w = 20;
	      rect.h = 20;
	      if (map.at(j).at(i)->get(Case::FOOD) >= 1)
		{
		  rect.x = (150 + (i - focus._x + 3) * _squareSize);
		  SDL_RenderCopy(renderer, _foodt, NULL, &rect);
		}
	      if (map.at(j).at(i)->get(Case::LIMEMATE) >= 1)
		{
		  rect.x = (170 + (i - focus._x + 3) * _squareSize);
		  SDL_RenderCopy(renderer, _rock1t, NULL, &rect);
		}
	      if (map.at(j).at(i)->get(Case::DERAUMERE) >= 1)
		{
		  rect.x = (190 + (i - focus._x + 3) * _squareSize);
		  SDL_RenderCopy(renderer, _rock2t, NULL, &rect);
		}
	      if (map.at(j).at(i)->get(Case::SIBUR) >= 1)
		{
		  rect.x = (210 + (i - focus._x + 3) * _squareSize);
		  SDL_RenderCopy(renderer, _rock3t, NULL, &rect);
		}
	      if (map.at(j).at(i)->get(Case::MENDIANE) >= 1)
		{
		  rect.x = (230 + (i - focus._x + 3) * _squareSize);
		  SDL_RenderCopy(renderer, _rock4t, NULL, &rect);
		}
	      rect.y = (170 + (j - focus._y + 3) * _squareSize);
	      if (map.at(j).at(i)->get(Case::PHIRAS) >= 1)
		{
		  rect.x = (150 + (i - focus._x + 3) * _squareSize);
		  SDL_RenderCopy(renderer, _rock5t, NULL, &rect);
		}
	      if (map.at(j).at(i)->get(Case::THYSTAME) >= 1)
		{
		  rect.x = (170 + (i - focus._x + 3) * _squareSize);
		  SDL_RenderCopy(renderer, _rock6t, NULL, &rect);
		}
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
      if ((*it)->getPosition()._x >= focus._x - 3 && (*it)->getPosition()._x <= focus._x + 3 && (*it)->getPosition()._y >= focus._y - 3 && (*it)->getPosition()._y <= focus._y + 3)
	{
	  SDL_Rect rect;
	  if ((*it)->isBroadcasting())
	    {
	      rect.x = (220 + ((*it)->getPosition()._x - focus._x + 3) * _squareSize);
	      rect.y = (50 + ((*it)->getPosition()._y - focus._y + 3) * _squareSize);
	      rect.w = 50;
	      rect.h = 50;
	      SDL_RenderCopy(renderer, _bubblet, NULL, &rect);
	      (*it)->updateBroadcast();
	    }
	  rect.x = (150 + ((*it)->getPosition()._x - focus._x + 3) * _squareSize);
	  rect.y = (100 + ((*it)->getPosition()._y - focus._y + 3) * _squareSize);
	  rect.w = 100;
	  rect.h = 142;
	  SDL_RenderCopy(renderer, _sprites.at((*it)->getLVL() - 1).at((*it)->getOrientation() - 1), NULL, &rect);
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
