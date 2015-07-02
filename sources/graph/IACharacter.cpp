//
// IACharacter.cpp for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Thu Jun 25 17:25:03 2015 Serge Heitzler
// Last update Thu Jul  2 15:17:28 2015 Nicolas Girardot
//

#include "IACharacter.hh"

IACharacter::IACharacter(std::vector<int> &args, std::string &teamName)
{
  this->_id = args.at(0);
  this->_position = new Position(args.at(1), args.at(2));
  this->_orientation = args.at(3);
  this->_lvl = args.at(4);
  this->_team = teamName;
}

IACharacter::~IACharacter()
{

}

int	IACharacter::getLVL()
{
  return (_lvl);
}

int	IACharacter::getOrientation()
{
  return (_orientation);
}

void	IACharacter::updateBroadcast()
{
  _broadcastCountdown--;
  if (_broadcastCountdown <= 0)
    _broadcasting = false;
}

bool	IACharacter::isBroadcasting()
{
  return (_broadcasting);
}

void	IACharacter::broadcast()
{
  _broadcasting = true;
  _broadcastCountdown = 1000;
}

Position	&IACharacter::getPosition()
{
  return (*_position);
}

void	IACharacter::updateAtt(std::vector<int> &args)
{
  this->_position->_x = args.at(1);
  this->_position->_y = args.at(2);
  this->_orientation = args.at(3);
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
