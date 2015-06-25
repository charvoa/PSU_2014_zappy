//
// HUD.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Jun 24 09:27:00 2015 Nicolas Girardot
// Last update Wed Jun 24 17:01:34 2015 Nicolas Girardot
//

#include "HUD.hh"
#include <iostream>

HUD::HUD(SDL_Renderer *renderer)
{
  this->_renderer = renderer;
  this->_font = TTF_OpenFont("fonts/font.ttf", 24);
  if (!_font)
    std::cout << TTF_GetError() << std::endl;
  this->_caseCurrent = TTF_RenderText_Solid(_font, "X Y", _white);
  this->_foodLocked = TTF_RenderText_Solid(_font, "Nourriture", _white);
  this->_rock1Locked = TTF_RenderText_Solid(_font, "Rock1", _white);
  this->_rock2Locked = TTF_RenderText_Solid(_font, "Rock2", _white);
  this->_rock3Locked = TTF_RenderText_Solid(_font, "Rock3", _white);
  this->_rock4Locked = TTF_RenderText_Solid(_font, "Rock4", _white);
  this->_rock5Locked = TTF_RenderText_Solid(_font, "Rock5", _white);
  this->_rock6Locked = TTF_RenderText_Solid(_font, "Rock6", _white);
  this->_caseLocked = TTF_RenderText_Solid(_font, "X Y", _white);
  this->_caseCurrentt = SDL_CreateTextureFromSurface(renderer, this->_caseCurrent);
  this->_foodLockedt = SDL_CreateTextureFromSurface(renderer, this->_foodLocked);
  this->_rock1Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock1Locked);
  this->_rock2Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock2Locked);
  this->_rock3Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock3Locked);
  this->_rock4Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock4Locked);
  this->_rock5Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock5Locked);
  this->_rock6Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock6Locked);
  this->_caseLockedt = SDL_CreateTextureFromSurface(renderer, this->_caseLocked);
}

HUD::~HUD() {}

void	HUD::updateCase(Position &pos)
{
  std::string result;
  std::stringstream sstm;
  sstm << pos._x << "/" << pos._y;
  result = sstm.str();
  this->_caseCurrent = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_caseCurrentt = SDL_CreateTextureFromSurface(_renderer, this->_caseCurrent);
}

void	HUD::updateLocked(Position &pos)
{
  std::string result;
  std::stringstream sstm;
  sstm << pos._x << "/" << pos._y;
  result = sstm.str();
  this->_caseLocked = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_caseLockedt = SDL_CreateTextureFromSurface(_renderer, this->_caseCurrent);
}

void	HUD::update()
{

}

void	HUD::draw(SDL_Renderer* renderer)
{
  drawHUDRight(renderer);
  drawHUDTop(renderer);
}

void	HUD::drawHUDTop(SDL_Renderer* renderer)
{
  SDL_Rect _drawer;
  _drawer.x = 450;
  _drawer.y = 75;
  _drawer.w = 100;
  _drawer.h = 50;
  SDL_RenderCopy(renderer, _caseCurrentt, NULL, &_drawer);
}

void	HUD::drawHUDRight(SDL_Renderer* renderer)
{
  SDL_Rect _drawer;
  _drawer.x = 850;
  _drawer.y = 175;
  _drawer.w = 100;
  _drawer.h = 50;
  SDL_RenderCopy(renderer, _foodLockedt, NULL, &_drawer);
  _drawer.y = 275;
  SDL_RenderCopy(renderer, _rock1Lockedt, NULL, &_drawer);
  _drawer.y = 375;
  SDL_RenderCopy(renderer, _rock2Lockedt, NULL, &_drawer);
  _drawer.y = 475;
  SDL_RenderCopy(renderer, _rock3Lockedt, NULL, &_drawer);
  _drawer.y = 575;
  SDL_RenderCopy(renderer, _rock4Lockedt, NULL, &_drawer);
  _drawer.y = 675;
  SDL_RenderCopy(renderer, _rock5Lockedt, NULL, &_drawer);
  _drawer.y = 775;
  SDL_RenderCopy(renderer, _rock6Lockedt, NULL, &_drawer);
  _drawer.y = 100;
  SDL_RenderCopy(renderer, _caseLockedt, NULL, &_drawer);
}