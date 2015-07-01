//
// Egg.hh for zapyy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Jul  1 10:46:30 2015 Nicolas Girardot
// Last update Wed Jul  1 11:09:20 2015 Nicolas Girardot
//

#ifndef _EGG_HH_
# define _EGG_HH_

#include <vector>
#include <iostream>

class Egg
{
private:
  int	_x;
  int	_y;
  int	_id;
public:
  Egg(std::vector<int> &);
  ~Egg();
  int	getX();
  int	getY();
  int	getID();
};

#endif
