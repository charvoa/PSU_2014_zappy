/*
** cmd_pin.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:50 2015 Serge Heitzler
** Last update Tue Jun 23 20:10:31 2015 Serge Heitzler
*/

#include "server.h"

int		cmd_pin(t_server *s, t_client *c, const char *cmd)
{
  int		*id_targeted;
  char		*final;
  t_client	*target;
  char		*tmp;

  id_targeted = xmalloc(sizeof(int));
  sscanf(cmd, "ppo #%d", id_targeted);
  target = get_client_by_id(s->clients, *id_targeted);
  tmp = get_objects_from_inventory(target->inventory);
  final = xmalloc(sizeof(char) * (9 + istm(target->fd)
				  + istm((int)target->pos->x)
				  + istm((int)target->pos->y)
				  + strlen(tmp)));
  memset(final, 0, (9 + istm(target->fd)
		    + istm((int)target->pos->x)
		    + istm((int)target->pos->y)
		    + strlen(tmp)));
  sprintf(final, "ppo #%d %d %d %s\n", target->fd,
	  target->pos->x, target->pos->y, tmp);
  send_data(c->fd, final);
  return (SUCCESS);
}