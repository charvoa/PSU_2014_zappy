/*
** cmd_pdi.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Wed Jul  1 14:05:33 2015 Serge Heitzler
** Last update Fri Jul  3 19:47:03 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_pdi(t_server *s, t_client *c)
{
  char		*trame;
  int		size_malloc;

  size_malloc = (7 + istm(c->fd));
  trame = xmalloc(sizeof(char) * size_malloc);
  bzero(trame, size_malloc);
  sprintf(trame, "pdi #%d\n", c->fd);
  send_data_to_gui(s->clients, trame);
  free(trame);
  return (SUCCESS);
}
