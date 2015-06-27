//
// HUD.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Jun 24 09:27:00 2015 Nicolas Girardot
// Last update Sat Jun 27 14:16:01 2015 Nicolas Girardot
//

#include "HUD.hh"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <png.h>
#include <zlib.h>

HUD::HUD(SDL_Renderer *renderer)
{
  this->_renderer = renderer;
  this->_font = TTF_OpenFont("fonts/font.ttf", 24);
  this->_background = IMG_Load("./background.png");
  std::cout << SDL_GetError() << std::endl;
  if (!_font)
    std::cout << TTF_GetError() << std::endl;

  this->_caseCurrent = TTF_RenderText_Solid(_font, "X Y", _white);

  //Right

  this->_caseLocked = TTF_RenderText_Solid(_font, "X Y", _white);
  this->_foodLocked = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock1Locked = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock2Locked = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock3Locked = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock4Locked = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock5Locked = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock6Locked = TTF_RenderText_Solid(_font, "0", _white);


  this->_foodLockedt = SDL_CreateTextureFromSurface(renderer, this->_foodLocked);
  this->_rock1Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock1Locked);
  this->_rock2Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock2Locked);
  this->_rock3Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock3Locked);
  this->_rock4Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock4Locked);
  this->_rock5Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock5Locked);
  this->_rock6Lockedt = SDL_CreateTextureFromSurface(renderer, this->_rock6Locked);
  this->_caseLockedt = SDL_CreateTextureFromSurface(renderer, this->_caseLocked);

  //Bottom

  this->_foodBottom = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock1Bottom = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock2Bottom = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock3Bottom = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock4Bottom = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock5Bottom = TTF_RenderText_Solid(_font, "0", _white);
  this->_rock6Bottom = TTF_RenderText_Solid(_font, "0", _white);
  this->_teamBottom = TTF_RenderText_Solid(_font, "0", _white);
  this->_playerID = TTF_RenderText_Solid(_font, "0", _white);
  this->_sprite = IMG_Load("./spriteBottom.png");

  this->_foodBottomt = SDL_CreateTextureFromSurface(renderer, this->_foodBottom);
  this->_rock1Bottomt = SDL_CreateTextureFromSurface(renderer, this->_rock1Bottom);
  this->_rock2Bottomt = SDL_CreateTextureFromSurface(renderer, this->_rock2Bottom);
  this->_rock3Bottomt = SDL_CreateTextureFromSurface(renderer, this->_rock3Bottom);
  this->_rock4Bottomt = SDL_CreateTextureFromSurface(renderer, this->_rock4Bottom);
  this->_rock5Bottomt = SDL_CreateTextureFromSurface(renderer, this->_rock5Bottom);
  this->_rock6Bottomt = SDL_CreateTextureFromSurface(renderer, this->_rock6Bottom);
  this->_teamBottomt = SDL_CreateTextureFromSurface(renderer, this->_teamBottom);
  this->_playerIDt = SDL_CreateTextureFromSurface(renderer, this->_playerID);
  this->_spritet = SDL_CreateTextureFromSurface(renderer, this->_sprite);

  //Right

  this->_backgroundt = SDL_CreateTextureFromSurface(renderer, this->_background);
  this->_caseCurrentt = SDL_CreateTextureFromSurface(renderer, this->_caseCurrent);
}

HUD::~HUD() {}

void	HUD::updateCase(Position &pos)
{
  std::string result;
  std::stringstream sstm;
  sstm << pos._x << "/" << pos._y;
  result = sstm.str();
  this->_caseCurrent = TTF_RenderText_Solid(_font, result.c_str(), _black);
  this->_caseCurrentt = SDL_CreateTextureFromSurface(_renderer, this->_caseCurrent);
}

void	HUD::updateLocked(int a, int b, Case *mycase)
{
  std::string result;
  std::stringstream sstm;
  sstm << a << "/" << b;
  result = sstm.str();
  this->_caseLocked = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_caseLockedt = SDL_CreateTextureFromSurface(_renderer, this->_caseLocked);

  sstm.str("");
  sstm.clear();
  sstm << mycase->get(Case::FOOD);
  result = sstm.str();
  this->_foodLocked = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_foodLockedt = SDL_CreateTextureFromSurface(_renderer, this->_foodLocked);

  sstm.str("");
  sstm.clear();
  sstm << mycase->get(Case::LIMEMATE);
  result = sstm.str();
  this->_rock1Locked = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock1Lockedt = SDL_CreateTextureFromSurface(_renderer, this->_rock1Locked);

  sstm.str("");
  sstm.clear();
  sstm << mycase->get(Case::DERAUMERE);
  result = sstm.str();
  this->_rock2Locked = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock2Lockedt = SDL_CreateTextureFromSurface(_renderer, this->_rock2Locked);

  sstm.str("");
  sstm.clear();
  sstm << mycase->get(Case::SIBUR);
  result = sstm.str();
  this->_rock3Locked = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock3Lockedt = SDL_CreateTextureFromSurface(_renderer, this->_rock3Locked);

  sstm.str("");
  sstm.clear();
  sstm << mycase->get(Case::MENDIANE);
  result = sstm.str();
  this->_rock4Locked = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock4Lockedt = SDL_CreateTextureFromSurface(_renderer, this->_rock4Locked);

  sstm.str("");
  sstm.clear();
  sstm << mycase->get(Case::PHIRAS);
  result = sstm.str();
  this->_rock5Locked = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock5Lockedt = SDL_CreateTextureFromSurface(_renderer, this->_rock5Locked);

  sstm.str("");
  sstm.clear();
  sstm << mycase->get(Case::THYSTAME);
  result = sstm.str();
  this->_rock6Locked = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock6Lockedt = SDL_CreateTextureFromSurface(_renderer, this->_rock6Locked);
}

void	HUD::update()
{

}

void	HUD::draw(SDL_Renderer* renderer)
{
  SDL_Rect _drawer;
  _drawer.x = 0;
  _drawer.y = 0;
  _drawer.w = 1000;
  _drawer.h = 1000;
  SDL_RenderCopy(renderer, _backgroundt, NULL, &_drawer);
  drawHUDRight(renderer);
  drawHUDTop(renderer);
  drawHUDBottom(renderer);
}

void	HUD::drawHUDBottom(SDL_Renderer *renderer)
{
  SDL_Rect _drawer;

  _drawer.x = 280;
  _drawer.y = 895;
  _drawer.w = 80;
  _drawer.h = 95;

  SDL_RenderCopy(renderer, _spritet, NULL , &_drawer);

  _drawer.x = 490;
  _drawer.y = 860;
  _drawer.w = 20;
  _drawer.h = 20;

  SDL_RenderCopy(renderer, _playerIDt, NULL, &_drawer);

  _drawer.y = 910;
  SDL_RenderCopy(renderer, _inventoryTitlet, NULL, &_drawer);

  _drawer.x = 550;
  SDL_RenderCopy(renderer, _foodBottomt, NULL, &_drawer);

  _drawer.x = 650;
  SDL_RenderCopy(renderer, _teamBottomt, NULL, &_drawer);

  _drawer.y = 960;
  _drawer.x = 380;
  SDL_RenderCopy(renderer, _rock1Bottomt, NULL, &_drawer);

  _drawer.x = 440;
  SDL_RenderCopy(renderer, _rock2Bottomt, NULL, &_drawer);

  _drawer.x = 500;
  SDL_RenderCopy(renderer, _rock3Bottomt, NULL, &_drawer);

  _drawer.x = 560;
  SDL_RenderCopy(renderer, _rock4Bottomt, NULL, &_drawer);

  _drawer.x = 620;
  SDL_RenderCopy(renderer, _rock5Bottomt, NULL, &_drawer);

  _drawer.x = 680;
  SDL_RenderCopy(renderer, _rock6Bottomt, NULL, &_drawer);
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
  _drawer.x = 930;
  _drawer.y = 225;
  _drawer.w = 20;
  _drawer.h = 20;
  SDL_RenderCopy(renderer, _foodLockedt, NULL, &_drawer);

  _drawer.y = 300;
  SDL_RenderCopy(renderer, _rock1Lockedt, NULL, &_drawer);

  _drawer.y = 375;
  SDL_RenderCopy(renderer, _rock2Lockedt, NULL, &_drawer);

  _drawer.y = 450;
  SDL_RenderCopy(renderer, _rock3Lockedt, NULL, &_drawer);

  _drawer.y = 525;
  SDL_RenderCopy(renderer, _rock4Lockedt, NULL, &_drawer);

  _drawer.y = 600;
  SDL_RenderCopy(renderer, _rock5Lockedt, NULL, &_drawer);

  _drawer.y = 675;
  SDL_RenderCopy(renderer, _rock6Lockedt, NULL, &_drawer);

  _drawer.w = 75;
  _drawer.h = 40;
  _drawer.x = 890;
  _drawer.y = 125;
  SDL_RenderCopy(renderer, _caseLockedt, NULL, &_drawer);
}
