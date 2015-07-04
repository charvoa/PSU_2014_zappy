/*
** server.c for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:25:19 2015 Nicolas Charvoz
** Last update Sat Jul  4 16:24:43 2015 Audibert Louis
*/

#include "functions.h"

int		main(int argc, char **argv)
{
  t_server	*s;

  srand(time(NULL));
  s = fill_struct_serv(argc, argv);
  init_socket(s);
  bind_socket(s, s->port);
  xlisten(s->listener, 10);
  FD_SET(s->listener, &(s->master));
  s->fdmax = s->listener;
  loop_server(s, argv);
  return (0);
}
