/*
** main.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 13:23:08 2015 Serge Heitzler
// Last update Tue May 26 18:35:28 2015 Nicolas Girardot
*/

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
