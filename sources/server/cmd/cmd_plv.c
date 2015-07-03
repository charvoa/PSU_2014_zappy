/*
** cmd_plv.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:28:57 2015 Serge Heitzler
** Last update Fri Jul  3 19:46:52 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_plv(t_server *s, t_client *c,
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
    sscanf(cmd, "plv #%d", id_targeted);
  target = get_client_by_id(s->clients, *id_targeted);
  size_malloc = 8 + istm(target->fd)
    + istm((int)target->level);
  final = malloc_and_memset(size_malloc);
  sprintf(final, "plv #%d %d\n", target->fd, target->level);
  if (type == GUI)
    send_data_to_gui(s->clients, final);
  else
    send_data(c->fd, final);
  free(final);
  return (SUCCESS);
}
