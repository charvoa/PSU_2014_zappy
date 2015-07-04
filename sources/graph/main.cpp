//
// main.cpp for zappy in /home/nicolas/rendu/PSU_2014_zappy/sources/graph
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Jun 22 15:23:29 2015 Nicolas Girardot
// Last update Sat Jul  4 16:24:31 2015 Nicolas Girardot
//


#include "AObject.hh"
#include "GameEngine.hh"
#include "Map.hpp"
#include "Socket.hh"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <exception>

int	main(int ac, char **av)
{
  try
    {
      srand(time(NULL));
      if (ac != 3)
	std::cout << "Wrong Usage : ./zappy_graph [IP] [PORT]" << std::endl;
      else
	{
	  GameEngine test;
	  test.run(av[1], std::stoi(av[2]));
	}
    }
  catch (std::exception &e)
    {
      std::cerr << "Error :" << e.what() << std::endl;
    }
  return (0);
}
