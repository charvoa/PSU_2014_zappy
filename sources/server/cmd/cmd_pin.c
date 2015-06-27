/*
** cmd_pin.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:50 2015 Serge Heitzler
** Last update Sat Jun 27 17:31:37 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_pin(t_server *s, t_client *c,
			const char *cmd, e_client_type type)
{
  int		size_malloc;
  int		*id_targeted;
  char		*final;
  t_client	*t;

  id_targeted = xmalloc(sizeof(int));  
  if (type == GUI)
    id_targeted = c->fd;
  else
    sscanf(cmd, "pin #%d", id_targeted);
  target = get_client_by_id(s->clients, *id_targeted);
  size_malloc = (15 + istm(t->fd) + istm((int)t->pos->x) + istm((int)t->pos->y)
		 + istm(t->food) + istm(t->linemate) + istm(t->deraumere)
		 + istm(t->sibur) + istm(t->mendiane) + istm(t->phiras)
		 + istm(t->thystame));
  final = xmalloc(sizeof(char) * size_malloc);
  memset(final, 0, size_malloc);
  sprintf(final, "pin #%d %d %d %d %d %d %d %d %d %d\n", t->fd, t->pos->x,
	  t->pos->y, t->food, t->linemate, t->deraumere, t->sibur,
	  t->mendiane, t->phiras, t->thystame);
  if (type == GUI)
    send_data_to_gui(s->clients, final);
  else
    send_data(c->fd, final);
  return (SUCCESS);
}
