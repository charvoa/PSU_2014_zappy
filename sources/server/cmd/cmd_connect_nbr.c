/*
** cmd_connect_nbr.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 26 17:10:37 2015 Audibert Louis
** Last update Sun Jul  5 14:10:17 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_connect_nbr(t_server *s, t_client *c,
				char *cmd, e_client_type type)
{
  (void)cmd;
  (void)type;
  t_team	*team;
  char		*trame;

  if (c->state == CHILD)
    return (ERROR);
  if (is_a_team(s, c->team_name) == 0)
    {
      team = get_team_by_name(s->teams, c->team_name);
      trame = malloc_and_memset(istm(team->slot_rest) + 2);
      sprintf(trame, "%d\n", team->slot_rest);
      send_data(c->fd, trame);
      free(trame);
      return (SUCCESS);
    }
  else
    send_data(c->fd, "ko\n");
  return (ERROR);
}
