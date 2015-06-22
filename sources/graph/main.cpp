//
// main.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Jun 22 15:23:29 2015 Nicolas Girardot
// Last update Mon Jun 22 15:23:30 2015 Nicolas Girardot
//


#include "AObject.hpp"
#include "GameEngine.hpp"
#include "Map.hpp"
#include "Socket.hh"

int	main(int ac, char **av)
{
  (void) ac;
  (void) av;
  GameEngine *test = new GameEngine();
  test->run();

  return (0);
}
