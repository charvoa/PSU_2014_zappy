/*
** cmd_sgt.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:58 2015 Serge Heitzler
** Last update Tue Jun 23 20:09:43 2015 Serge Heitzler
*/

#include "server.h"

int		cmd_sgt(t_server *s, t_client *c, const char *cmd)
{
  (void)cmd;
  char		*final;

  final = xmalloc(sizeof(char) *
		  (5 + istm(s->time_action)));
  memset(final, 0, 5 + istm(s->time_action));
  sprintf(final, "sgt %d\n", s->time_action);
  send_data(c->fd, final);
  return (SUCCESS);
}