/*
** main.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 13:23:08 2015 Serge Heitzler
// Last update Wed May 13 11:05:36 2015 Nicolas Girardot
*/

#include "Socket.hh"

int	main(int ac, char **av)
{
  ac = ac;
  Socket *s = new Socket(av[1], atoi(av[2]));
  s->initSocket();
  s->connectSocket();
  s->selectSocket();
  return (0);
}
