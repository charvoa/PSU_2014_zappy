//
// HUD.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Jun 24 09:27:00 2015 Nicolas Girardot
// Last update Sun Jul  5 16:37:04 2015 Nicolas Girardot
//

#include "HUD.hh"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <png.h>
#include <zlib.h>

HUD::HUD(SDL_Renderer *renderer)
{
  _descdrawer.x = 350;
  _descdrawer.y = 20;
  _descdrawer.w = 300;
  _descdrawer.h = 50;
  this->_renderer = renderer;
  this->_font = TTF_OpenFont("fonts/font.ttf", 24);
  this->_background = IMG_Load("./background.png");
  std::cout << SDL_GetError() << std::endl;
  if (!_font)
    std::cout << TTF_GetError() << std::endl;

  this->_caseCurrent = TTF_RenderText_Solid(_font, "X Y", _black);
  this->_description = TTF_RenderText_Solid(_font, "INFORMATIONS !", _black);
  this->_descriptiont = SDL_CreateTextureFromSurface(renderer, this->_description);

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
  this->_teamBottom = TTF_RenderText_Solid(_font, "", _white);
  this->_playerID = TTF_RenderText_Solid(_font, "", _white);
  this->_sprite = IMG_Load("zelda_sprites/1-3.png");

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

  //Left

  this->_teamLeft = TTF_RenderText_Solid(_font, "1", _white);
  this->_nbrPlayer = TTF_RenderText_Solid(_font, "2", _white);
  this->_nbrPlayer8 = TTF_RenderText_Solid(_font, "1", _white);

  this->_teamLeftt = SDL_CreateTextureFromSurface(renderer, this->_teamLeft);
  this->_nbrPlayert = SDL_CreateTextureFromSurface(renderer, this->_nbrPlayer);
  this->_nbrPlayer8t = SDL_CreateTextureFromSurface(renderer, this->_nbrPlayer8);

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

void	HUD::updateTeamInfo(std::string &a, int b, int c)
{
  std::string result;
  std::stringstream sstm;
  sstm << c;
  result = sstm.str();
  this->_nbrPlayer8 = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_nbrPlayer8t = SDL_CreateTextureFromSurface(_renderer, this->_nbrPlayer8);
  sstm.str("");
  sstm.clear();
  sstm << b;
  result = sstm.str();
  this->_nbrPlayer = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_nbrPlayert = SDL_CreateTextureFromSurface(_renderer, this->_nbrPlayer);
  sstm.str("");
  sstm.clear();
  sstm << a;
  result = sstm.str();
  this->_teamLeft = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_teamLeftt = SDL_CreateTextureFromSurface(_renderer, this->_teamLeft);
}

void	HUD::updateInventory(IACharacter *charac)
{
  std::string result;
  std::stringstream sstm;

  sstm << charac->get(IACharacter::FOOD);
  result = sstm.str();
  this->_foodBottom = TTF_RenderText_Solid(_font, result.c_str() ,_white);
  this->_foodBottomt = SDL_CreateTextureFromSurface(_renderer, this->_foodBottom);

  sstm.str("");
  sstm.clear();
  sstm << charac->get(IACharacter::LIMEMATE);
  result = sstm.str();
  this->_rock1Bottom = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock1Bottomt = SDL_CreateTextureFromSurface(_renderer, this->_rock1Bottom);

  sstm.str("");
  sstm.clear();
  sstm << charac->get(IACharacter::DERAUMERE);
  result = sstm.str();
  this->_rock2Bottom = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock2Bottomt = SDL_CreateTextureFromSurface(_renderer, this->_rock2Bottom);


  sstm.str("");
  sstm.clear();
  sstm << charac->get(IACharacter::SIBUR);
  result = sstm.str();
  this->_rock3Bottom = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock3Bottomt = SDL_CreateTextureFromSurface(_renderer, this->_rock3Bottom);

  sstm.str("");
  sstm.clear();
  sstm << charac->get(IACharacter::PHIRAS);
  result = sstm.str();
  this->_rock4Bottom = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock4Bottomt = SDL_CreateTextureFromSurface(_renderer, this->_rock4Bottom);

  sstm.str("");
  sstm.clear();
  sstm << charac->get(IACharacter::THYSTAME);
  result = sstm.str();
  this->_rock5Bottom = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock5Bottomt = SDL_CreateTextureFromSurface(_renderer, this->_rock5Bottom);


  sstm.str("");
  sstm.clear();
  sstm << charac->get(IACharacter::MENDIANE);
  result = sstm.str();
  this->_rock6Bottom = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_rock6Bottomt = SDL_CreateTextureFromSurface(_renderer, this->_rock6Bottom);


  sstm.str("");
  sstm.clear();
  sstm << charac->getTeam();
  result = sstm.str();
  this->_teamBottom = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_teamBottomt = SDL_CreateTextureFromSurface(_renderer, this->_teamBottom);


  sstm.str("");
  sstm.clear();
  sstm << "Player" << charac->getId();
  result = sstm.str();
  this->_playerID = TTF_RenderText_Solid(_font, result.c_str(), _white);
  this->_playerIDt = SDL_CreateTextureFromSurface(_renderer, this->_playerID);
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

void	HUD::update_info(std::string &info)
{
  int	length = info.size();
  _descdrawer.x = 500 - length / 2 * 20;
  _descdrawer.y = 20;
  _descdrawer.w = length * 20;
  _descdrawer.h = 50;
  this->_description = TTF_RenderText_Solid(_font, info.c_str(), _black);
  this->_descriptiont = SDL_CreateTextureFromSurface(_renderer, this->_description);
}

void	HUD::draw(SDL_Renderer* renderer)
{
  SDL_Rect _drawer;
  _drawer.x = 0;
  _drawer.y = 0;
  _drawer.w = 1000;
  _drawer.h = 1000;
  SDL_RenderCopy(renderer, _backgroundt, NULL, &_drawer);
  drawHUDLeft(renderer);
  drawHUDRight(renderer);
  drawHUDTop(renderer);
  drawHUDBottom(renderer);
}

void	HUD::drawHUDLeft(SDL_Renderer *renderer)
{
   SDL_Rect _drawer;

  _drawer.x = 5;
  _drawer.y = 225;
  _drawer.w = 15 * 9;
  _drawer.h = 20;

  SDL_RenderCopy(renderer, _teamLeftt, NULL, &_drawer);

  _drawer.x = 50;
  _drawer.y = 425;
  _drawer.w = 20;
  _drawer.h = 20;
  SDL_RenderCopy(renderer, _nbrPlayert, NULL, &_drawer);
  _drawer.y = 625;
  SDL_RenderCopy(renderer, _nbrPlayer8t, NULL, &_drawer);
}

void	HUD::drawHUDBottom(SDL_Renderer *renderer)
{
  SDL_Rect _drawer;

  _drawer.x = 270;
  _drawer.y = 880;
  _drawer.w = 80;
  _drawer.h = 95;

  SDL_RenderCopy(renderer, _spritet, NULL , &_drawer);

  _drawer.x = 430;
  _drawer.y = 860;
  _drawer.w = 20 * 7;
  _drawer.h = 20;

  SDL_RenderCopy(renderer, _playerIDt, NULL, &_drawer);


  _drawer.w = 20;
  _drawer.y = 910;
  SDL_RenderCopy(renderer, _inventoryTitlet, NULL, &_drawer);

  _drawer.x = 570;
  _drawer.y = 905;
  SDL_RenderCopy(renderer, _foodBottomt, NULL, &_drawer);

  _drawer.y = 900;
  _drawer.x = 620;
  _drawer.w = 20 * 5;
  SDL_RenderCopy(renderer, _teamBottomt, NULL, &_drawer);


  _drawer.w = 20;
  _drawer.y = 960;
  _drawer.x = 345;
  SDL_RenderCopy(renderer, _rock1Bottomt, NULL, &_drawer);

  _drawer.x = 407;
  SDL_RenderCopy(renderer, _rock2Bottomt, NULL, &_drawer);

  _drawer.x = 472;
  SDL_RenderCopy(renderer, _rock3Bottomt, NULL, &_drawer);

  _drawer.x = 537;
  SDL_RenderCopy(renderer, _rock4Bottomt, NULL, &_drawer);

  _drawer.x = 602;
  SDL_RenderCopy(renderer, _rock5Bottomt, NULL, &_drawer);

  _drawer.x = 667;
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
  SDL_RenderCopy(renderer, _descriptiont, NULL, &_descdrawer);
}

void	HUD::drawHUDRight(SDL_Renderer* renderer)
{
  SDL_Rect _drawer;
  _drawer.x = 930;
  _drawer.y = 225;
  _drawer.w = 20;
  _drawer.h = 20;
  SDL_RenderCopy(renderer, _foodLockedt, NULL, &_drawer);

  _drawer.y = 287;
  SDL_RenderCopy(renderer, _rock1Lockedt, NULL, &_drawer);

  _drawer.y = 353;
  SDL_RenderCopy(renderer, _rock2Lockedt, NULL, &_drawer);

  _drawer.y = 418;
  SDL_RenderCopy(renderer, _rock3Lockedt, NULL, &_drawer);

  _drawer.y = 482;
  SDL_RenderCopy(renderer, _rock4Lockedt, NULL, &_drawer);

  _drawer.y = 550;
  SDL_RenderCopy(renderer, _rock5Lockedt, NULL, &_drawer);

  _drawer.y = 618;
  SDL_RenderCopy(renderer, _rock6Lockedt, NULL, &_drawer);

  _drawer.w = 75;
  _drawer.h = 40;
  _drawer.x = 890;
  _drawer.y = 125;
  SDL_RenderCopy(renderer, _caseLockedt, NULL, &_drawer);
}
