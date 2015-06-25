//
// IACharacter.cpp for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Thu Jun 25 17:25:03 2015 Serge Heitzler
// Last update Thu Jun 25 17:28:31 2015 Serge Heitzler
//

#include "IACharacter.hh"

IACharacter::IACharacter()
{

}

IACharacter::~IACharacter()
{

}

void	IACharacter::increment(e_type type)
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

void	IACharacter::decrement(e_type type)
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

int	IACharacter::get(e_type type)
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
}
