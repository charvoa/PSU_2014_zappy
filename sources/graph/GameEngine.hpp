//
// Game.hh for Zappy in /home/florian/rendu/SystemeUnix/PSU_2014_zappy/sources/graph
// 
// Made by Florian PERU
// Login   <florian@epitech.eu>
// 
// Started on  Wed May  6 15:12:05 2015 Florian PERU
// Last update Wed May 20 14:15:57 2015 Florian PERU
//

#ifndef _GAMEENGINE_HPP_
#define _GAMEENGINE_HPP_

#include <iostream>
#include <OpenGl.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>

class	GameEngine : public gdl::Game
{
public:
  GameEngine::GameEngine() {}
  GameEngine::~GameEngine() {
    for (size_t i = 0; i < _object.size(); i++)
      delete _object[i];
  }

  void	GameEngine::init_object()
  {
    AObject	*map = new Map;

    if (map->initialize() == true)
      _object.push_back(map);
    /* Ajouter les autres Object TODO */
  }

  bool	GameEngine::initialize()
  {
    glm::mat4	projection;
    glm::mat4	transform;

    if (_context.start(800, 600, "Zappy"))
      return false;
    glEnable(GL_DEPTH_TEST);
    if (!_shader.load("./libGDL/shaders/basic.fp", GL_FRAGMENT_SHADER)
	|| !_shader.load("./libGDL/shaders/basic.vp", GL_VERTEX_SHADER)
	|| !_shader.build())
      return false;

    projection = glm::perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    transform = glm::lookAt(glm::vec3(à, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

    _shader.bind();
    _shader.setUniform("view", transform);
    _shader.setUniform("projection", projection);

    init_object();
    return true;
  }

  bool	GameEngine::update()
  {
    if (_input.getKey(SDLK_ESCAPE) || _input.getKey(SDLK_QUIT))
      return false;

    _context.updateClock(_clock);
    _context.updateInputs(_input);

    for (size_t i = 0; i < _object.size(); i++)
      _object[i]->update(_clock, _input);

    return true;
  }

  void	GameEngine::draw()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (size_t i = 0; i < _object.size(); i++)
      _object[i].draw(_shader, _clock);

    _context.flush()
  }

private:
  gdl::SdlContext		_context;
  gdl::Clock			_clock;
  gdl::BasicShader		_shader;
  gdl::Input			_input;
  std::vector<AObject *>	_object;
}

#endif
