/*
** cmd_tna.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:28:48 2015 Serge Heitzler
** Last update Wed Jul  1 10:20:42 2015 Serge Heitzler
*/

#include "functions.h"

char		*get_all_teams_in_str(t_server *s)
{
  int		i;
  int		size;
  char		*res;

  i = 0;
  size = 0;
  while (i < get_nbr_of(TEAM, s->teams))
    size += (strlen(get_team_name_at_index(s->teams, i++)) + 1);
  res = xmalloc(sizeof(char) * size);
  memset(res, 0, size);
  i = 0;
  sprintf(res, "%s\n", get_team_name_at_index(s->teams, i++));  
  while (i < get_nbr_of(TEAM, s->teams))
    sprintf(res, "%s%s\n", res, get_team_name_at_index(s->teams, i++));
  return (res);
}

int		cmd_tna(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  (void)cmd;
  char		*final;
  char		*all_teams;

  all_teams = get_all_teams_in_str(s);
  final = xmalloc(sizeof(char) * (5 + strlen(all_teams)));
  memset(final, 0, (5 + strlen(all_teams)));
  sprintf(final, "tna %s\n", all_teams);
  if (type == GUI)
    send_data_to_gui(s->clients, final);
  else
    send_data(c->fd, final);
  return (SUCCESS);
}
