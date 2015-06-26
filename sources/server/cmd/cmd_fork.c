/*
** cmd_fork.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:37 2015 Serge Heitzler
** Last update Fri Jun 26 16:35:26 2015 Audibert Louis
*/

#include "server.h"

static void	cmd_gui_pfk(t_client *c, t_list *clients)
{
  char	*str;

  str = xmalloc(strlen("pfk# \n") + 50 * sizeof(char));
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
