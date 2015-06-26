/*
** cmd_fork.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:37 2015 Serge Heitzler
** Last update Fri Jun 26 13:43:55 2015 Antoine Garcia
*/

#include "server.h"

static void	cmd_gui_pfk(t_client *c, t_list *clients)
{
  char	*str;

  str = malloc(strlen("pfk# \n") + 50 * sizeof(char));
  sprintf(str, "pfk #%d\n", c->fd);
  send_data_to_gui(clients, str);
}

int		cmd_fork(t_server *s, t_client *c, const char *cmd)
{
  (void)cmd;
  (void)s;
  (void)c;

  cmd_gui_pfk(c, s->clients);
  return (SUCCESS);
}
