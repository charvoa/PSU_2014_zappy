//
// Case.cpp for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Thu Jun 25 10:50:53 2015 Serge Heitzler
// Last update Thu Jun 25 17:29:58 2015 Serge Heitzler
//

#include "Case.hh"

Case::Case(int linemate, int deraumere, int sibur, int mediane, int phiras, int thystame, int food)
{
  _limemate = linemate;
  _deraumere = deraumere;
  _sibur = sibur;
  _mendiane = mediane;
  _phiras = phiras;
  _thystame = thystame;
  _food = food;
}

Case::~Case()
{

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
