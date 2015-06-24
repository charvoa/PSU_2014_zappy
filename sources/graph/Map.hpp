//
// Map.hpp for Zappy in /home/florian/rendu/SystemeUnix/PSU_2014_zappy/sources/graph
//
// Made by Florian PERU
// Login   <florian@epitech.eu>
//
// Started on  Fri May 15 14:00:16 2015 Florian PERU
// Last update Tue Jun 23 16:53:33 2015 Nicolas Girardot
//

#ifndef MAP_HPP_
#define MAP_HPP_

#include "AObject.hh"

class	Map
{
private:

public:
  Map() {}
  virtual ~Map() {}

  virtual bool	initialize() {
    return true;
  }

  virtual void	draw()
  {
  }
};

#endif
