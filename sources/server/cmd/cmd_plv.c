/*
** cmd_plv.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:28:57 2015 Serge Heitzler
** Last update Tue Jun 23 20:10:23 2015 Serge Heitzler
*/

#include "server.h"

int		cmd_plv(t_server *s, t_client *c, const char *cmd)
{
  int		*id_targeted;
  char		*final;
  t_client	*target;

  id_targeted = xmalloc(sizeof(int));
  sscanf(cmd, "plv #%d", id_targeted);
  target = get_client_by_id(s->clients, *id_targeted);
  final = xmalloc(sizeof(char) * (7 + istm(target->fd)
				  + istm((int)target->level)));
  memset(final, 0, (7 + istm(target->fd)
		    + istm((int)target->level)));
  sprintf(final, "plv #%d %d\n", target->fd, target->level);
  send_data(c->fd, final);
  return (SUCCESS);
}
