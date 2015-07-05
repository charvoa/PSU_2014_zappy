/*
** cmd_pin.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:50 2015 Serge Heitzler
** Last update Sun Jul  5 19:23:36 2015 Audibert Louis
*/

#include "functions.h"

int		get_pin_malloc(t_client *t)
{
  int		size_malloc;

  size_malloc = (16 + istm(t->fd)
		 + istm((int)t->pos->x) + istm((int)t->pos->y)
		 + istm(t->inventory->food) + istm(t->inventory->linemate)
		 + istm(t->inventory->deraumere) + istm(t->inventory->sibur)
		 + istm(t->inventory->mendiane) + istm(t->inventory->phiras)
		 + istm(t->inventory->thystame));
  return (size_malloc);
}

int		cmd_pin(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  int		size_malloc;
  int		*id_targeted;
  char		*final;
  t_client	*t;

  id_targeted = xmalloc(sizeof(int));
  if (type == GUI)
    *id_targeted = c->fd;
  else
    sscanf(cmd, "pin #%d", id_targeted);
  t = get_client_by_id(s->clients, *id_targeted);
  size_malloc = get_pin_malloc(t);
  final = xmalloc(sizeof(char) * size_malloc);
  memset(final, 0, size_malloc);
  sprintf(final, "pin #%d %d %d %d %d %d %d %d %d %d\n", t->fd, t->pos->x,
	  t->pos->y, t->inventory->food, t->inventory->linemate,
	  t->inventory->deraumere, t->inventory->sibur,
	  t->inventory->mendiane, t->inventory->phiras,
	  t->inventory->thystame);
  if (type == GUI)
    send_data_to_gui(s->clients, final);
  else
    send_data(c->fd, final);
  free(final);
  return (SUCCESS);
}
