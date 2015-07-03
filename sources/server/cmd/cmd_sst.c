/*
** cmd_sst.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:28:52 2015 Serge Heitzler
** Last update Fri Jul  3 18:50:47 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_sst(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  char		*final;
  char		value[6];

  memset(value, 0, 6);
  sscanf(cmd, "sst %s", value);
  s->time_action = atoi(value);
  final = xmalloc(sizeof(char) *
		  (6 + strlen(value)));
  memset(final, 0, 6 + strlen(value));
  sprintf(final, "sgt %s\n", value);
  if (type == GUI)
    send_data_to_gui(s->clients, final);
  else
    send_data(c->fd, final);
  free(final);
  return (SUCCESS);
}
