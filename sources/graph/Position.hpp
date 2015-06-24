//
// Position.hpp for Position in /home/antgar/rendu/cpp_bomberman
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat May 23 19:49:40 2015 Antoine Garcia
// Last update Tue Jun  2 16:20:40 2015 Antoine Garcia
//

#ifndef POSITION_HPP_
# define POSITION_HPP_

class	Position
{
public:
  int	_x;
  int	_y;

  Position(){}
  Position(int x, int y)
  {
    _x = x;
    _y = y;
  }

  void	setPosition(Position &newpos)
  {
    _x = newpos._x;
    _y = newpos._y;
  }
  int   getX()
  {
    return _x;
  }
  int   getY()
  {
    return _y;
  }
  void  setX(int x)
  {
    _x = x;
  }
  void  setY(int y)
  {
    _y = y;
  }
  inline bool	operator==(const Position& pos)
  {
    if (pos._x == _x && pos._y == _y)
      return true;
    return false;
  }

  inline Position&	operator=(const Position& pos)
  {
    _x = pos._x;
    _y = pos._y;
    return *this;
  }
};

#endif
