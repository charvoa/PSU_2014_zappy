/*
** cmd_inventory.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:41 2015 Serge Heitzler
** Last update Fri Jul  3 19:02:06 2015 Serge Heitzler
*/

#include "functions.h"

char		*get_objects_from_inventory(t_inventory *i)
{
  int		size_malloc;
  char		*res;

  size_malloc = (78 + istm(i->food)
		 + istm(i->linemate) + istm(i->deraumere)
		 + istm(i->sibur) + istm(i->mendiane)
		 + istm(i->phiras) + istm(i->thystame));
  res = xmalloc(sizeof(char) * size_malloc);
  memset(res, 0, size_malloc);
  sprintf(res, "{nourriture %d, linemate %d, deraumere %d, \
sibur %d, mendiane %d, phiras %d, thystame %d}\n",
	  i->food, i->linemate, i->deraumere, i->sibur,
	  i->mendiane, i->phiras, i->thystame);
  return (res);
}

int		cmd_inventory(t_server *s, t_client *c,
			      char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  (void)s;
  char		*final;

  final = get_objects_from_inventory(c->inventory);
  send_data(c->fd, final);
  free(final);
  return (SUCCESS);
}
