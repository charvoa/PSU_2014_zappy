//
// IACharacter.cpp for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Thu Jun 25 17:25:03 2015 Serge Heitzler
// Last update Tue Jun 30 17:18:46 2015 Nicolas Girardot
//

#include "IACharacter.hh"

IACharacter::IACharacter(std::vector<std::string> &args)
{
  this->_id = stoi(args.at(0));
  this->_position = new Position(stoi(args.at(1)), stoi(args.at(2)));
  this->_orientation = stoi(args.at(3));
  this->_lvl = stoi(args.at(4));
  this->_team = args.at(5);
}

IACharacter::~IACharacter()
{

}

Position	*IACharacter::getPosition()
{
  return (_position);
}

void	IACharacter::updateAtt(std::vector<std::string> &args)
{
  this->_position->_x = stoi(args.at(1));
  this->_position->_y = stoi(args.at(2));
  this->_orientation = stoi(args.at(3));
}

void	IACharacter::updateInventory(std::vector<int> &inv)
{
  _food = inv.at(3);
  _limemate = inv.at(4);
  _deraumere = inv.at(5);
  _sibur = inv.at(6);
  _mendiane = inv.at(7);
  _phiras = inv.at(8);
  _thystame = inv.at(9);
}

void	IACharacter::setLVL(int lvl)
{
  this->_lvl = lvl;
}

std::string &IACharacter::getTeam()
{
  return (_team);
}

int	IACharacter::getId()
{
  return (_id);
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
  return 1;
}
