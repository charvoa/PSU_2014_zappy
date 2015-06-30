/*
** cmd_plv.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:28:57 2015 Serge Heitzler
** Last update Wed Jul  1 10:24:10 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_plv(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  int		*id_targeted;
  char		*final;
  t_client	*target;

  id_targeted = xmalloc(sizeof(int));
  if (type == GUI)
    *id_targeted = c->fd;
  else
    sscanf(cmd, "plv #%d", id_targeted);
  target = get_client_by_id(s->clients, *id_targeted);
  final = xmalloc(sizeof(char) * (8 + istm(target->fd)
				  + istm((int)target->level)));
  memset(final, 0, (8 + istm(target->fd)
		    + istm((int)target->level)));
  sprintf(final, "plv #%d %d\n", target->fd, target->level);
  if (type == GUI)
    send_data_to_gui(s->clients, final);
  else
    send_data(c->fd, final);
  return (SUCCESS);
}
