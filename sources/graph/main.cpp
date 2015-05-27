/*
** main.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 13:23:08 2015 Serge Heitzler
// Last update Wed May 27 11:15:15 2015 Nicolas Girardot
*/

#include "AObject.hpp"
#include "GameEngine.hpp"
#include "Map.hpp"
#include "Socket.hh"

int	main(int ac, char **av)
{
  (void) ac;
  Socket *connect = new Socket(av[1], atoi(av[2]));
  GameEngine *test = new GameEngine();
  test->run();
  connect->my_connect();

  return (0);
}
