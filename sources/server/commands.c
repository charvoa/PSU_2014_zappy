/*
** commands.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 16:30:08 2015 Audibert Louis
** Last update Tue Jun 23 14:46:50 2015 Audibert Louis
*/

#include "server.h"

int	is_a_team(t_server *s, char *team)
{
  int	i;

  i = 0;
  if (s->teams->names != NULL)
    {
      while (s->teams->names[i] != NULL)
	{
	  printf("s->teams->names[%d] = %s\n", i, s->teams->names[i]);
	  if (strcmp(s->teams->names[i], team) == 0)
	    return (0);
	  i++;
	}
    }
  return (-1);
}

int	cmd_team(t_server *s, t_client *c, const char *cmd)
{
  char	trame[21];
  char	*team;
  
  team = xmalloc((strlen(cmd) - 4) * sizeof(char));
  bzero(trame, 21);
  bzero(team, strlen(cmd) - 4);
  printf("test\n");
  sscanf(cmd, "TEAM %s", team);
  printf("team name received in cmd_team = %s\n", team);
  if (is_a_team(s, team) == 0)
    {
      if (s->teams->slot_rest >= 1)
	{
	  sprintf(trame, "%d", s->teams->slot_rest);
	  send_data(c->fd, trame);
	  bzero(c->team_name, strlen(team));
	  c->team_name = strdup(team);
	  s->teams->slot_rest --;
	}
      else
	send_data(c->fd, "NO_SLOT_REST\r\n");
    }
  bzero(trame, 21);
  sprintf(trame, "%d - %d\n", s->map->size->width, s->map->size->height);
  send_data(c->fd, trame);
  cmd_dead(s, c, "mort");
  return (0);
}
