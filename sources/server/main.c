/*
** server.c for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:25:19 2015 Nicolas Charvoz
** Last update Sun May 17 11:38:40 2015 Serge Heitzler
*/

#include "server.h"

int		main(int argc, char **argv)
{
  t_server	*s;
  
  srand(time(NULL));
  s = fill_struct_serv(argc, argv);
  init_socket(s);
  bind_socket(s, 4242);
  xlisten(s->listener, 10);
  FD_SET(s->listener, &(s->master));
  s->fdmax = s->listener;
  loop_server(s, argv);
  return (0);
}
