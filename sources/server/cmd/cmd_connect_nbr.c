/*
** cmd_connect_nbr.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 26 17:10:37 2015 Audibert Louis
** Last update Wed Jul  1 10:33:05 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_connect_nbr(t_server *s, t_client *c,
				char *cmd, e_client_type type)
{
  (void)cmd;
  (void)type;
  t_team	*team;
  char		*trame;

  if (is_a_team(s, c->team_name) == 0)
    {
      team = get_team_by_name(s->teams, c->team_name);
      trame = xmalloc((istm(team->slot_rest) + 2) * sizeof(char));
      sprintf(trame, "%d\n", team->slot_rest);
      send_data(c->fd, trame);
      return (SUCCESS);
    }
  else
    send_data(c->fd, "ko\n");
  return (ERROR);
}
