/*
** cmd_fork.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:37 2015 Serge Heitzler
** Last update Tue Jun 30 13:59:43 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_fork(t_server *s, t_client *c,
			 const char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  t_egg		*egg;
  t_team	*team;

  cmd_pfk(c, s->clients);
  team = get_team_by_name(s->teams, c->team_name);
  team->slot_rest++;
  egg = xmalloc(sizeof(t_egg));
  egg->id = c->fd;
  /* egg->fd_father = c->fd; */
  /* egg->fd_egg = ?; */
  egg->pos = xmalloc(sizeof(t_position));
  egg->pos->x = c->pos->x;
  egg->pos->y = egg->pos->y;
  egg->team_name = strdup(c->team_name);
  egg->state = ASLEEP;
  cmd_enw(s, c, type, egg->id);
  return (SUCCESS);
}
