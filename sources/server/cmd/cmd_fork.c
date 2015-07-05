/*
** cmd_fork.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:37 2015 Serge Heitzler
** Last update Sun Jul  5 14:10:34 2015 Audibert Louis
*/

#include "functions.h"

void		delay_inf(t_egg *e, int billion, long ns_delay)
{
  if (e->eclos.tv_nsec + ns_delay > billion)
    {
      e->eclos.tv_sec++;
      e->eclos.tv_nsec = e->eclos.tv_nsec + ns_delay - billion;
    }
  else
    e->eclos.tv_nsec += ns_delay;
}

void		delay_sup(t_egg *e, int billion, long ns_delay)
{
  int		mod;

  e->eclos.tv_sec += ns_delay / billion;
  mod = ns_delay % billion;
  if (e->eclos.tv_nsec + mod > billion)
    {
      e->eclos.tv_sec++;
      mod = e->eclos.tv_nsec + mod;
    }
  e->eclos.tv_nsec += mod;
}

void		get_eclosion(t_server *s, t_egg *e)
{
  float		rate;
  int		billion;
  long		ns_delay;

  billion = 1000000000;
  rate = 642 / s->time_action;
  ns_delay = rate * billion;
  if (ns_delay > billion)
    delay_sup(e, billion, ns_delay);
  else
    delay_inf(e, billion, ns_delay);
}

int		cmd_fork(t_server *s, t_client *c,
			 char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  static int	id = 0;
  t_egg		*egg;
  t_team	*team;

  if (c->state == CHILD)
    return (ERROR);
  cmd_pfk(c, s->clients);
  team = get_team_by_name(s->teams, c->team_name);
  team->slot_rest++;
  egg = xmalloc(sizeof(t_egg));
  egg->fd = -1;
  egg->fd_father = c->fd;
  egg->id = id;
  egg->pos = xmalloc(sizeof(t_position));
  egg->pos->x = c->pos->x;
  egg->pos->y = c->pos->y;
  egg->team_name = strdup(c->team_name);
  clock_gettime(CLOCK_REALTIME, &egg->eclos);
  get_eclosion(s, egg);
  push_back(s->eggs, egg, EGG);
  cmd_enw(s, c, egg, GUI);
  return (SUCCESS);
}
