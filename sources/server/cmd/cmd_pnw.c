/*
** cmd_pnw.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sat Jun 27 15:10:59 2015 Serge Heitzler
** Last update Fri Jul  3 19:55:11 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_pnw_normal(t_server *s, t_client *c,
			       e_client_type type, int fd)
{
  (void)type;
  int		size_malloc;
  char		*final;

  size_malloc = (12 + istm(c->fd)
		 + istm((int)c->pos->x)
		 + istm((int)c->pos->y)
		 + istm(c->orientation)
		 + istm(c->level)
		 + strlen(c->team_name));
  final = xmalloc(sizeof(char) * size_malloc);
  memset(final, 0, size_malloc);
  sprintf(final, "pnw #%d %d %d %d %d %s\n", c->fd, c->pos->x,
	  c->pos->y, c->orientation, c->level, c->team_name);
  if (type == GUI)
    send_data_to_gui(s->clients, final);
  else
    send_data(fd, final);
  free(final);
  return (SUCCESS);
}

int		cmd_pnw_all(t_server *s, t_client *c,
			    char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  t_node	*tmp;
  t_client	*cli;

  if (s->clients->length > 0)
    {
      tmp = s->clients->start;
      while (tmp)
	{
	  cli = tmp->data;
	  if (cli->type == IA && cli->state == ADULT)
	    cmd_pnw_normal(s, cli, IA, c->fd);
	  tmp = tmp->next;
	}
    }
  return (SUCCESS);
}

int		cmd_pnw(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  if (type == NORMAL)
    cmd_pnw_normal(s, c, GUI, c->fd);
  else
    cmd_pnw_all(s, c, cmd, type);
  return (SUCCESS);
}
