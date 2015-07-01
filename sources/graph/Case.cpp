//
// Case.cpp for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Thu Jun 25 10:50:53 2015 Serge Heitzler
// Last update Wed Jul  1 10:42:01 2015 Nicolas Girardot
//

#include "Case.hh"
#include <iostream>

Case::Case(int limemate, int deraumere, int sibur, int mendiane, int phiras, int thystame, int food)
{
  _limemate = limemate;
  _deraumere = deraumere;
  _sibur = sibur;
  _mendiane = mendiane;
  _phiras = phiras;
  _thystame = thystame;
  _food = food;
  int tex = rand() % 2;
  if (tex == 1)
    _textureType = GRASS;
  else
    _textureType = DIRT;
}

Case::~Case()
{

}

int	Case::get(e_type type)
{
  if (type == LIMEMATE)
    return _limemate;
  if (type == DERAUMERE)
    return _deraumere;
  if (type == SIBUR)
    return _sibur;
  if (type == MENDIANE)
    return _mendiane;
  if (type == PHIRAS)
    return _phiras;
  if (type == THYSTAME)
    return _thystame;
  if (type == FOOD)
    return _food;
  return 0;
}

int	Case::getType()
{
  return this->_textureType;
}

void	Case::increment(e_type type)
{
  if (type == LIMEMATE)
    _limemate++;
  if (type == DERAUMERE)
    _deraumere++;
  if (type == SIBUR)
    _sibur++;
  if (type == MENDIANE)
    _mendiane++;
  if (type == PHIRAS)
    _phiras++;
  if (type == THYSTAME)
    _thystame++;
  if (type == FOOD)
    _food++;
}

void	Case::decrement(e_type type)
{
  if (type == LIMEMATE && _limemate > 0)
    _limemate--;
  if (type == DERAUMERE && _deraumere > 0)
    _deraumere--;
  if (type == SIBUR && _sibur > 0)
    _sibur--;
  if (type == MENDIANE && _mendiane > 0)
    _mendiane--;
  if (type == PHIRAS && _phiras > 0)
    _phiras--;
  if (type == THYSTAME && _thystame > 0)
    _thystame--;
  if (type == FOOD && _food > 0)
    _food--;
}

bool	Case::getIncant()
{
  return _isIncant;
}

void	Case::setIncant(bool status)
{
  _isIncant = status;
}

void	Case::setAll(int limemate, int deraumere, int sibur, int mendiane, int phiras, int thystame, int food)
{
  _limemate = limemate;
  _deraumere = deraumere;
  _sibur = sibur;
  _mendiane = mendiane;
  _phiras = phiras;
  _thystame = thystame;
  _food = food;
}
