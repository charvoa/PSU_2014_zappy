/*
** cmd_msz.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:01 2015 Serge Heitzler
** Last update Fri Jul  3 19:01:20 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_msz(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  char		*final;

  final = xmalloc(sizeof(char) * (7  + istm((int)s->map->size->width)
				  + istm((int)s->map->size->height)));
  memset(final, 0, (7 + istm((int)s->map->size->width)
		    + istm((int)s->map->size->height)));
  sprintf(final, "msz %d %d\n", s->map->size->width, s->map->size->height);
  send_data(c->fd, final);
  free(final);
  return (SUCCESS);
}
