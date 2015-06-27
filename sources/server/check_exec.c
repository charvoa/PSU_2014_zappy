/*
** check_exec.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 26 08:23:43 2015 Serge Heitzler
** Last update Sat Jun 27 14:13:28 2015 Serge Heitzler
*/

#include "functions.h"

int		check_exec(t_server *s)
{
  int		i;
  t_client	*c;
  t_node	*tmp_cli;
  t_node	*tmp_cmd;
  t_cmd		*cmd;

  i = 0;
  tmp_cli = s->clients->start;
  c = xmalloc(sizeof(t_client));
  cmd = xmalloc(sizeof(t_cmd));
  cmd->label = xmalloc(sizeof(char) * 50); // 50 en dur;
  while (i < s->clients->length)
    {
      c = tmp_cli->data;
      tmp_cmd = c->cmds->start;
      cmd = tmp_cmd->data;
      if (/*cmd->exec_at.tv_sec.tm_sec <= s->now.tv_sec.tm_sec &&*/ cmd->exec_at.tv_nsec < s->now.tv_nsec || i < s->clients->length) // diff time current_time && send_at || ATTENTION deuxieme condition toujours vraie !!! -> Pour test
	{
	  exec_cmd(s, c);
	  remove_front(c->cmds);
	}
      i++;
      tmp_cli = tmp_cli->next;
    }
  return (SUCCESS);
}
