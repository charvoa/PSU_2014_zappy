/*
** prepare_for_exec.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Sun Jun 28 00:07:48 2015 Serge Heitzler
** Last update Tue Jun 30 18:05:32 2015 Antoine Garcia
*/

#include "functions.h"

void		delay_inferior(t_cmd *cmd, long ns_delay, int billion)
{
  if (cmd->exec_at.tv_nsec + ns_delay > billion)
    {
      cmd->exec_at.tv_sec++;
      ns_delay = cmd->exec_at.tv_nsec + ns_delay - billion;
    }
  else
    cmd->exec_at.tv_nsec += ns_delay;
}

void		delay_superior(t_cmd *cmd, long ns_delay, int billion)
{
  int		mod;

  cmd->exec_at.tv_sec += ns_delay / billion;
  mod = ns_delay % billion;
  if (cmd->exec_at.tv_nsec + mod > billion)
    {
      cmd->exec_at.tv_sec++;
      mod = cmd->exec_at.tv_nsec + mod;
    }
  cmd->exec_at.tv_nsec += mod;
}

int		manage_time(t_server *s, t_cmd *cmd, int index)
{
  float		rate;
  long		ns_delay;
  int		billion;

  billion = 1000000000;
  rate = g_cmds[index].delay / s->time_action;
  ns_delay = rate * billion;
  if (ns_delay > billion)
    delay_superior(cmd, ns_delay, billion);
  else
    delay_inferior(cmd, ns_delay, billion);
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
  if ((ret = (is_cmd(s_cmd->label))) != NO)
    {
      printf("Time when received %ld,%ld\n", s_cmd->exec_at.tv_sec, s_cmd->exec_at.tv_nsec);
      manage_time(s, s_cmd, ret);
      printf("Exec cmd at %ld,%ld\n", s_cmd->exec_at.tv_sec, s_cmd->exec_at.tv_nsec);
    }
  push_back(c->cmds, s_cmd, CMD);
  free(tmp);
}
