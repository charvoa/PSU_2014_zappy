/*
** prepare_for_exec.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 26 08:23:46 2015 Serge Heitzler
** Last update Sat Jun 27 10:43:57 2015 Audibert Louis
*/

#include "functions.h"

static void	check_client_type(const char *cmd, t_client *c)
{
  if (!strcmp(cmd, "graph_cli_connected\r\n"))
    c->type = GUI;
}

void		prepare_for_exec(t_server *s, t_client *c)
{
  t_cmd		*s_cmd;

  (void)s;
  s_cmd = xmalloc(sizeof(t_cmd));
  s_cmd->label = ring_buffer_get_next_command(c->buffer);
  check_client_type(s_cmd->label, c);
  if (s_cmd->label == NULL)
    return;
  

  // getcurrentime(server);

  

  if (c->cmds->length < 10)
    push_back(c->cmds, s_cmd, CMD);
  else
    send_data(c->fd, "Cmd list is too long !\n");
  printf("CMD == %s\n", s_cmd->label);
}
