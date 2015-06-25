/*
** prepare_for_exec.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 26 08:23:46 2015 Serge Heitzler
** Last update Fri Jun 26 10:43:47 2015 Serge Heitzler
*/

#include "server.h"

void		prepare_for_exec(t_server *s, t_client *c)
{
  t_cmd		*s_cmd;
  char		*cmd;

  s_cmd = xmalloc(sizeof(t_cmd));
  s_cmd->label = ring_buffer_get_next_command(c->buffer);
  check_client_type(cmd->label, c);
  if (cmd->label == NULL)
    return;
  

  // getcurrentime(server);
  
  if (c->cmds->length >= 0 && c->cmds->length < 10)
    push_back(c->cmds, s_cmd, CMD);
  else
    send_data(c->fd, "Cmd list too long !\n");
  printf("CMD == %s\n", cmd);
}
