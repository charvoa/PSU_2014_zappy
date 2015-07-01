//
// Egg.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Jul  1 10:46:33 2015 Nicolas Girardot
// Last update Wed Jul  1 11:04:14 2015 Nicolas Girardot
//

#include "Egg.hh"

Egg::Egg(std::vector<int> &att)
{
  this->_id = att.at(0);
  this->_x = att.at(2);
  this->_y = att.at(3);
}

Egg::~Egg()
{

}

int	Egg::getX()
{
  return (_x);
}

int	Egg::getY()
{
  return (_y);
}

int	Egg::getID()
{
  return (_id);
}
