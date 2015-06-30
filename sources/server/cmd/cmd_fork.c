/*
** cmd_fork.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:37 2015 Serge Heitzler
** Last update Tue Jun 30 16:03:16 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_fork(t_server *s, t_client *c,
			 const char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  static int	id = 0;
  t_egg		*egg;
  t_team	*team;

  cmd_pfk(c, s->clients);
  team = get_team_by_name(s->teams, c->team_name);
  team->slot_rest++;
  egg = xmalloc(sizeof(t_egg));
  egg->fd = -1;
  egg->id = id;
  egg->pos = xmalloc(sizeof(t_position));
  egg->pos->x = c->pos->x;
  egg->pos->y = c->pos->y;
  egg->team_name = strdup(c->team_name);
  egg->state = ASLEEP;
  push_back(s->eggs, egg, EGG);
  cmd_enw(s, c, type, egg->id);
  return (SUCCESS);
}
