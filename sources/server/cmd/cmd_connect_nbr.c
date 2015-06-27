/*
** cmd_connect_nbr.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 26 17:10:37 2015 Audibert Louis
** Last update Sat Jun 27 16:52:11 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_connect_nbr(t_server *s, t_client *c,
				const char *cmd, e_client_type type)
{
  (void)cmd;
  (void)type;
  t_team	*team;

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
