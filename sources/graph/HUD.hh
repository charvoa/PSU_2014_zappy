//
// HUD.hh for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Jun 24 09:27:23 2015 Nicolas Girardot
// Last update Wed Jun 24 17:00:27 2015 Nicolas Girardot
//

#ifndef _HUD_HH_
#define _HUD_HH_

#include <sstream>
#include <SDL.h>
#include <SDL/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Position.hpp"

class HUD
{
private:
  SDL_Renderer *_renderer;
  TTF_Font *_font = NULL;
  SDL_Surface *_caseCurrent = NULL;
  SDL_Texture *_caseCurrentt = NULL;
  SDL_Surface *_caseLocked = NULL;
  SDL_Texture *_caseLockedt = NULL;
  SDL_Surface *_foodLocked = NULL;
  SDL_Texture *_foodLockedt = NULL;
  SDL_Surface *_rock1Locked = NULL;
  SDL_Texture *_rock1Lockedt = NULL;
  SDL_Surface *_rock2Locked = NULL;
  SDL_Texture *_rock2Lockedt = NULL;
  SDL_Surface *_rock3Locked = NULL;
  SDL_Texture *_rock3Lockedt = NULL;
  SDL_Surface *_rock4Locked = NULL;
  SDL_Texture *_rock4Lockedt = NULL;
  SDL_Surface *_rock5Locked = NULL;
  SDL_Texture *_rock5Lockedt = NULL;
  SDL_Surface *_rock6Locked = NULL;
  SDL_Texture *_rock6Lockedt = NULL;
  SDL_Color _white = {255, 255, 255, 42};

public:
  HUD(SDL_Renderer*);
  ~HUD();
  void	update();
  void	updateCase(Position&);
  void	updateLocked(Position &);
  void	draw(SDL_Renderer *);
  void	drawHUDRight(SDL_Renderer *);
  void	drawHUDTop(SDL_Renderer *);
};

#endif