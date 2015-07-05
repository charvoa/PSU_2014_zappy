/*
** cmd_ppo.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:54 2015 Serge Heitzler
** Last update Sun Jul  5 00:05:43 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_ppo(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  int		size_malloc;
  int		*id_targeted;
  char		*final;
  t_client	*target;

  id_targeted = xmalloc(sizeof(int));
  if (type == GUI)
    *id_targeted = c->fd;
  else
    sscanf(cmd, "ppo #%d", id_targeted);
  target = get_client_by_id(s->clients, *id_targeted);
  size_malloc = (10 + istm(target->fd)
		 + istm((int)target->pos->x)
		 + istm((int)target->pos->y)
		 + istm(target->orientation));
  final = malloc_and_memset(size_malloc);
  sprintf(final, "ppo #%d %d %d %d\n", target->fd,
	  target->pos->x, target->pos->y, target->orientation);
  if (type == GUI)
    send_data_to_gui(s->clients, final);
  else
    send_data(c->fd, final);
  free(final);
  return (SUCCESS);
}
