/*
** cmd_ppo.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:54 2015 Serge Heitzler
** Last update Sat Jun 27 10:50:38 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_ppo(t_server *s, t_client *c, const char *cmd)
{
  int		*id_targeted;
  char		*final;
  t_client	*target;

  id_targeted = xmalloc(sizeof(int));
  sscanf(cmd, "ppo #%d", id_targeted);
  target = get_client_by_id(s->clients, *id_targeted);
  final = xmalloc(sizeof(char) * (9 + istm(target->fd)
				  + istm((int)target->pos->x)
				  + istm((int)target->pos->y)
				  + istm(target->orientation)));
  memset(final, 0, (9 + istm(target->fd)
		    + istm((int)target->pos->x)
		    + istm((int)target->pos->y)
		    + istm(target->orientation)));
  sprintf(final, "ppo #%d %d %d %d\n", target->fd,
	  target->pos->x, target->pos->y, target->orientation);
  send_data(c->fd, final);
  return (SUCCESS);
}
