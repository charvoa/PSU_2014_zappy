//
// HUD.hh for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Jun 24 09:27:23 2015 Nicolas Girardot
// Last update Sat Jun 27 14:00:59 2015 Nicolas Girardot
//

#ifndef _HUD_HH_
#define _HUD_HH_

#include <sstream>
#include <SDL.h>
#include <SDL/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Position.hpp"
#include "Case.hh"

class HUD
{
private:
  SDL_Renderer *_renderer;
  TTF_Font *_font = NULL;
  SDL_Surface *_background = NULL;
  SDL_Texture *_backgroundt = NULL;
  SDL_Surface *_caseCurrent = NULL;
  SDL_Texture *_caseCurrentt = NULL;

  //HUD Right

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

  //HUD Bottom

  SDL_Surface *_sprite = NULL;
  SDL_Texture *_spritet = NULL;

  SDL_Surface *_playerID = NULL;
  SDL_Texture *_playerIDt = NULL;

  SDL_Surface *_inventoryTitle = NULL;
  SDL_Texture *_inventoryTitlet = NULL;

  SDL_Surface *_foodBottom = NULL;
  SDL_Texture *_foodBottomt = NULL;

  SDL_Surface *_rock1Bottom = NULL;
  SDL_Texture *_rock1Bottomt = NULL;

  SDL_Surface *_rock2Bottom = NULL;
  SDL_Texture *_rock2Bottomt = NULL;

  SDL_Surface *_rock3Bottom = NULL;
  SDL_Texture *_rock3Bottomt = NULL;

  SDL_Surface *_rock4Bottom = NULL;
  SDL_Texture *_rock4Bottomt = NULL;

  SDL_Surface *_rock5Bottom = NULL;
  SDL_Texture *_rock5Bottomt = NULL;

  SDL_Surface *_rock6Bottom = NULL;
  SDL_Texture *_rock6Bottomt = NULL;

  SDL_Surface *_teamBottom = NULL;
  SDL_Texture *_teamBottomt = NULL;

  //HUD Left

  // SDL_Surface * = NULL;
  // SDL_Texture * = NULL;

  // SDL_Surface * = NULL;
  // SDL_Texture * = NULL;

  // SDL_Surface * = NULL;
  // SDL_Texture * = NULL;

  // SDL_Surface * = NULL;
  // SDL_Texture * = NULL;

  // SDL_Surface * = NULL;
  // SDL_Texture * = NULL;

  // SDL_Surface * = NULL;
  // SDL_Texture * = NULL;

  // SDL_Surface * = NULL;
  // SDL_Texture * = NULL;

  // SDL_Surface * = NULL;
  // SDL_Texture * = NULL;

  // SDL_Surface * = NULL;
  // SDL_Texture * = NULL;

  //Color

  SDL_Color _white = {255, 255, 255, 42};
  SDL_Color _black = {0, 0, 0, 42};

public:
  HUD(SDL_Renderer*);
  ~HUD();
  void	update();
  void	updateCase(Position &);
  void	updateLocked(int, int, Case *);
  void	draw(SDL_Renderer *);
  void	drawHUDRight(SDL_Renderer *);
  void	drawHUDBottom(SDL_Renderer *);
  void	drawHUDTop(SDL_Renderer *);
};

#endif
