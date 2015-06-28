/*
** prepare_for_exec.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jun 28 00:07:48 2015 Serge Heitzler
** Last update Sun Jun 28 12:50:38 2015 Serge Heitzler
*/

#include "functions.h"

int		manage_time(t_server *s, t_cmd *cmd, int index)
{
  float		rate;
  long		ns_delay;
  int		mod;
  int		billion;

  billion = 1000000000;
  rate = g_cmds[index].delay / s->time_action;
  ns_delay = rate * billion;
  printf("rate %f nsdelay %ld\n", rate, ns_delay);
  if (ns_delay > billion)
    {
      printf("A\n");
      cmd->exec_at.tv_sec += ns_delay / billion; 
      mod = ns_delay % billion;
      if (cmd->exec_at.tv_nsec + mod > billion)
	{
	  printf("B\n");
	  cmd->exec_at.tv_sec++;
	  mod = cmd->exec_at.tv_nsec + mod;
	}
      cmd->exec_at.tv_nsec += mod;
    }
  else
    {
      printf("C\n");
      if (cmd->exec_at.tv_nsec + ns_delay > billion)
	{
	  printf("D\n");
	  cmd->exec_at.tv_sec++;
	  ns_delay = cmd->exec_at.tv_nsec + ns_delay - billion;
	}
      else
	cmd->exec_at.tv_nsec += ns_delay;
    }
  return (SUCCESS);
}

void		create_cmd(t_server *s, t_client *c)
{
  (void)s;
  int			ret;
  char			*tmp;
  t_cmd			*s_cmd;

  if (c->cmds->length >= 10)
    {
      send_data(c->fd, "Cmd list is too long !\n");
      return;
    }

  tmp = ring_buffer_get_next_command(c->buffer);
  if (tmp == NULL)
    return;
  if ((strncmp(tmp, "incantation", strlen("incantation"))) == 0
      && ((is_incantation_possible(s, c, tmp, NORMAL)) == NO))
    return;

  s_cmd = xmalloc(sizeof(t_cmd));
  s_cmd->label = strdup(tmp);
  clock_gettime(CLOCK_REALTIME, &s_cmd->exec_at);

  printf("CMD = %s\n", s_cmd->label);

  if ((ret = (is_cmd(s_cmd->label))) != NO)
    {
      printf("BEFORE s = %ld\nns = %ld\nx/t = %f\n", s_cmd->exec_at.tv_sec, s_cmd->exec_at.tv_nsec, g_cmds[ret].delay / s->time_action);
      manage_time(s, s_cmd, ret);
      printf("AFTER s = %ld\nns = %ld\nx/t = %f\n", s_cmd->exec_at.tv_sec, s_cmd->exec_at.tv_nsec, g_cmds[ret].delay / s->time_action);
    }
  push_back(c->cmds, s_cmd, CMD);
}
