/*
** cmd_connect_nbr.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 26 17:10:37 2015 Audibert Louis
** Last update Fri Jun 26 17:32:00 2015 Audibert Louis
*/

#include "server.h"

int		cmd_connect_nbr(t_server *s, t_client *c, const char *cmd)
{
  t_team	*team;

  (void)cmd;
  if (is_a_team(s, c->team_name) == 0)
    {
      team = get_team_by_name(s->teams, c->team_name);
      team->slot_rest++;
      send_data(c->fd, "ok\n");
      return (SUCCESS);
    }
  send_data(c->fd, "ko\n");
  return (ERROR);
}
