/*
** cmd_sgt.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:58 2015 Serge Heitzler
** Last update Sun Jun 28 00:32:11 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_sgt(t_server *s, t_client *c,
			const char *cmd, e_client_type type)
{
  (void)cmd;
  char		*final;

  final = xmalloc(sizeof(char) *
		  (5 + istm(s->time_action)));
  memset(final, 0, 5 + istm(s->time_action));
  sprintf(final, "sgt %.0f\n", s->time_action);
  if (type == GUI)
    send_data_to_gui(s->clients, final);
  else
    send_data(c->fd, final);
  return (SUCCESS);
}
