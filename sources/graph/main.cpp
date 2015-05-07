/*
** main.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 13:23:08 2015 Serge Heitzler
// Last update Thu May  7 15:46:21 2015 Nicolas Girardot
*/

#include "Socket.hh"

int	main(int ac, char **av)
{
  (void)ac;
  (void)av;
  Socket *s = new Socket("127.0.0.1", atoi("4444"));
  s->initSocket();
  s->connectSocket();
  s->selectSocket();
  return (0);
}
