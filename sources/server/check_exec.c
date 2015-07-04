/*
** check_exec.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 26 08:23:43 2015 Serge Heitzler
** Last update Sun Jul  5 00:36:24 2015 Serge Heitzler
*/

#include "functions.h"

void		exec_and_remove(t_server *s, t_client *c)
{
  exec_cmd(s, c);
  remove_front(c->cmds);
}

int		check_exec(t_server *s)
{
  int		i;
  t_client	*c;
  t_node	*tmp_cli;
  t_node	*tmp_cmd;
  t_cmd		*cmd;

  i = -1;
  tmp_cli = s->clients->start;
  while (++i < s->clients->length)
    {
      c = tmp_cli->data;
      if (c->cmds->length > 0)
	{
	  tmp_cmd = c->cmds->start;
	  cmd = tmp_cmd->data;
	  if (cmd->exec_at.tv_sec < s->now.tv_sec ||
	      ((cmd->exec_at.tv_sec == s->now.tv_sec) &&
	       (cmd->exec_at.tv_nsec <= s->now.tv_nsec)))
	    exec_and_remove(s, c);
	}
      tmp_cli = tmp_cli->next;
    }
  return (SUCCESS);
}
