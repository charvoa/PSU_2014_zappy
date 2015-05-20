//
// Map.hpp for Zappy in /home/florian/rendu/SystemeUnix/PSU_2014_zappy/sources/graph
// 
// Made by Florian PERU
// Login   <florian@epitech.eu>
// 
// Started on  Fri May 15 14:00:16 2015 Florian PERU
// Last update Fri May 15 14:24:43 2015 Florian PERU
//

#ifndef _MAP_HPP_
#define _MAP_HPP_

#include "AObject.hpp"

class	Map : public AObject
{
private:
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;

public:
  Map() {}
  virtual ~Map() {}

  virtual bool	initialize() {
    if (_texture.load("texture_path.tga") == false)
      {
	std::cerr << "Can't find this texture" << std::endl;
	return false;
      }

    return true;
  }
}

#endif