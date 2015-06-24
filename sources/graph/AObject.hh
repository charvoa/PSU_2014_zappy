//
// AObject.hh for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Jun 23 15:43:22 2015 Nicolas Girardot
// Last update Tue Jun 23 16:53:13 2015 Nicolas Girardot
//

#ifndef _AOBJECT_HH_
#define _AOBJECT_HH_

class AObject
{
protected:
  int	_posX;
  int	_posY;
public:
  AObject();
  virtual ~AObject();
  virtual bool	initialize();
  virtual void	update();
  virtual void	draw();
};

#endif
