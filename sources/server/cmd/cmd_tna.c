/*
** cmd_tna.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:28:48 2015 Serge Heitzler
** Last update Thu Jul  2 12:05:29 2015 Serge Heitzler
*/

#include "functions.h"

void		send_all_teams(t_server *s, t_client *c)
{
  int		i;
  char		*res;
  int		size;

  i = 0;
  printf("NB TEAM %d \n", get_nbr_of(TEAM, s->teams));
  while (i < get_nbr_of(TEAM, s->teams))
    {
      size = (strlen(get_team_name_at_index(s->teams, i)) + 1);
      printf("size = %d\n", size);
      res = xmalloc(sizeof(char) * size);
      memset(res, 0, size);
      printf("TEAM[%d] = %s\n", i, get_team_name_at_index(s->teams, i));
      sprintf(res, "%s\n", get_team_name_at_index(s->teams, i));
      printf("%s", res);
      send_data(c->fd, res);
      free(res);
      i++;
    }
}

int		cmd_tna(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  (void)cmd;
  (void)type;
  send_all_teams(s, c);
  return (SUCCESS);
}
