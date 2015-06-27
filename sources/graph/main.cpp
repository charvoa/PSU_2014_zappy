//
// main.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Jun 22 15:23:29 2015 Nicolas Girardot
// Last update Fri Jun 26 17:19:01 2015 Nicolas Girardot
//


#include "AObject.hh"
#include "GameEngine.hh"
#include "Map.hpp"
#include "Socket.hh"
#include <time.h>
#include <stdlib.h>


int	main(int ac, char **av)
{
  (void) ac;
  (void) av;
  GameEngine test;
  test.run();
  srand(time(NULL));
  return (0);
}
