//
// AObject.hpp for Zappy in /home/florian/rendu/SystemeUnix/PSU_2014_zappy/sources/graph
//
// Made by Florian PERU
// Login   <florian@epitech.eu>
//
// Started on  Thu May  7 15:30:04 2015 Florian PERU
// Last update Tue May 26 18:16:43 2015 Nicolas Girardot
//

#ifndef _AOBJECT_HPP_
#define _AOBJECT_HPP_

#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <BasicShader.hh>
#include <iostream>

class	AObject
{
protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;

public:
  AObject() :
    _position(0, 0, 0),
    _rotation(0, 0, 0),
    _scale(1, 1, 1) {}
  virtual	~AObject () {}

  virtual bool	initialize() {
    return true;
  }

  virtual void	update(gdl::Clock const & clock, gdl::Input & input)
  {
    (void) clock;
    (void) input;
  }

  virtual void	draw(gdl::BasicShader & shader, gdl::Clock const & clock) = 0;

  void	translate(glm::vec3 const & vect)
  {
    _position += vect;
  }

  void	rotate(glm::vec3 const & axe, float angle)
  {
    _rotation += axe * angle;
  }

  void	scale(glm::vec3 const & scale)
  {
    _scale *= scale;
  }

  glm::mat4	getTransform()
  {
    glm::mat4	transform(1);

    transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
    transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
    transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));

    transform = glm::translate(transform, _position);
    transform = glm::scale(transform, _scale);

    return transform;
  }
};

#endif
