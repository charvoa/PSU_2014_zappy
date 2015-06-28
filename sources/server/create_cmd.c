/*
** prepare_for_exec.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jun 28 00:07:48 2015 Serge Heitzler
** Last update Sun Jun 28 12:10:02 2015 Serge Heitzler
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
  t_cmd			*s_cmd;

  if (c->cmds->length >= 10)
    {
      send_data(c->fd, "Cmd list is too long !\n");
      return;
    }
  s_cmd = xmalloc(sizeof(t_cmd));
  s_cmd->label = ring_buffer_get_next_command(c->buffer);
  if (s_cmd->label == NULL)
    return;
  if (!(strncmp(s_cmd->label, "incantation", strlen("incantation")) != 0
  	&& (is_incantation_possible(s, c, s_cmd->label, NORMAL)) == NO))
    return;
  if ((ret = (is_cmd(s_cmd->label))) != NO)
    {
      // INIT Obligatoire de exec_at pour éviter erreur valgrind
      clock_gettime(CLOCK_REALTIME, &s_cmd->exec_at);
      printf("BEFORE s = %ld\nns = %ld\nx/t = %f\n", s_cmd->exec_at.tv_sec, s_cmd->exec_at.tv_nsec, g_cmds[ret].delay / s->time_action);
      manage_time(s, s_cmd, ret);
      printf("AFTER s = %ld\nns = %ld\nx/t = %f\n", s_cmd->exec_at.tv_sec, s_cmd->exec_at.tv_nsec, g_cmds[ret].delay / s->time_action);
    }
  push_back(c->cmds, s_cmd, CMD);
  printf("CMD == %s\n", s_cmd->label);
}
