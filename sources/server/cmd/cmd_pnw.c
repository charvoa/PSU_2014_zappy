/*
** cmd_pnw.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sat Jun 27 15:10:59 2015 Serge Heitzler
** Last update Sat Jun 27 18:51:10 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_pnw(t_server *s, t_client *c,
			const char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  int		size_malloc;
  char		*final;

  size_malloc = (11 + istm(c->fd)
		 + istm((int)c->pos->x)
		 + istm((int)c->pos->y)
		 + istm(c->orientation)
		 + istm(c->level)
		 + strlen(c->team_name) + 1);
  final = xmalloc(sizeof(char) * size_malloc);
  memset(final, 0, size_malloc);
  sprintf(final, "pnw #%d %d %d %d %d %s\n", c->fd, c->pos->x,
	  c->pos->y, c->orientation, c->level, c->team_name);
  printf("size[%zu]\n", strlen(final));
  printf("%s", final);
  send_data_to_gui(s->clients, final);
  return (SUCCESS);
}
