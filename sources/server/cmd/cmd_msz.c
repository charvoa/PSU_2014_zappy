/*
** cmd_msz.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:01 2015 Serge Heitzler
** Last update Fri Jun 19 11:29:03 2015 Serge Heitzler
*/

#include "server.h"

int		cmd_msz(t_server *s, t_client *c, const char *cmd)
{
  (void)cmd;
  char		*final;

  final = xmalloc(sizeof(char) * (5  + int_size_to_malloc((int)s->map->size->width)
				  + int_size_to_malloc((int)s->map->size->height)));
  memset(final, 0, (5 + int_size_to_malloc((int)s->map->size->width)
		    + int_size_to_malloc((int)s->map->size->height)));
  sprintf(final, "msz %d %d\n", s->map->size->width, s->map->size->height);
  send_data(c->fd, final);
  return (SUCCESS);
}
