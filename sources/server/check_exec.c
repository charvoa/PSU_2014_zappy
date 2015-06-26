/*
** check_exec.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 26 08:23:43 2015 Serge Heitzler
** Last update Fri Jun 26 16:27:51 2015 Serge Heitzler
*/

#include "server.h"

int		check_exec(t_server *s)
{
  size_t	i;
  t_client	*c;
  t_node	*tmp;
  t_cmd		*cmd;

  i = 0;
  tmp = s->clients->start;
  c = xmalloc(sizeof(t_client));
  cmd = xmalloc(sizeof(t_cmd));
  cmd->label = xmalloc(sizeof(char) * 50); // 50 en dur;
  while (i < s->clients->length)
    {
      c = tmp->data;
      cmd = c->cmds->start;
      if (cmd->send_at > s->current_time || i < s->clients->length) // diff time current_time && send_at || ATTENTION deuxieme condition toujours vraie !!! -> Pour test
	{
	  exec_cmd(s, c);
	  remove_front(c->cmds);
	}
      i++;
    }
  return (SUCCESS);
}
