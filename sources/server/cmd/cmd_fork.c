/*
** cmd_fork.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:37 2015 Serge Heitzler
** Last update Sat Jun 27 16:30:53 2015 Serge Heitzler
*/

#include "functions.h"

static void	cmd_gui_pfk(t_client *c, t_list *clients)
{
  char	*str;

  str = xmalloc(strlen("pfk# \n") + 50 * sizeof(char));
  sprintf(str, "pfk #%d\n", c->fd);
  send_data_to_gui(clients, str);
}

int		cmd_fork(t_server *s, t_client *c,
			 const char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  (void)s;
  (void)c;

  cmd_gui_pfk(c, s->clients);
  return (SUCCESS);
}
