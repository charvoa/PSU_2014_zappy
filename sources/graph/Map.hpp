//
// Map.hpp for Zappy in /home/florian/rendu/SystemeUnix/PSU_2014_zappy/sources/graph
//
// Made by Florian PERU
// Login   <florian@epitech.eu>
//
// Started on  Fri May 15 14:00:16 2015 Florian PERU
// Last update Fri Jun 19 16:40:28 2015 Nicolas Girardot
//

#ifndef _MAP_HPP_
#define _MAP_HPP_

#include "AObject.hpp"

class	Map : public AObject
{
private:

public:
  Map() {}
  virtual ~Map() {}

  virtual bool	initialize() {
    return true;
  }

  virtual void	draw(gdl::BasicShader & shader, gdl::Clock const & clock)
  {
    (void) shader;
    (void) clock;
  }
};

#endif
