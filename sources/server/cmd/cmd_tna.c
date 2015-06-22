/*
** cmd_tna.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:28:48 2015 Serge Heitzler
** Last update Fri Jun 19 11:28:49 2015 Serge Heitzler
*/

#include "server.h"

char		*get_all_teams_in_str(t_server *s)
{
  int		i;
  int		size;
  char		*res;

  i = 0;
  size = 0;
  while (i < size_of_tab(s->teams->names))
    size += (strlen(s->teams->names[i++]) + 1);
  res = xmalloc(sizeof(char) * size);
  memset(res, 0, size);
  i = 0;
  while (i < size_of_tab(s->teams->names))
    sprintf(res, "%s \n", s->teams->names[i++]);
  return (res);
}

int		cmd_tna(t_server *s, t_client *c, const char *cmd)
{
  (void)cmd;
  char		*final;
  char		*all_teams;

  all_teams = get_all_teams_in_str(s);
  final = xmalloc(sizeof(char) * (5 + strlen(all_teams)));
  memset(final, 0, (5 + strlen(all_teams)));
  sprintf(final, "tna %s\n", all_teams);
  send_data(c->fd, final);
  return (SUCCESS);
}
