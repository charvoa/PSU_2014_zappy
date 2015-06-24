/*
** commands.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 16:30:08 2015 Audibert Louis
** Last update Wed Jun 24 10:35:14 2015 Audibert Louis
*/

#include "server.h"

int	is_a_team(t_server *s, char *team)
{
  t_node	*tmp;
  t_team	*t_iterate;

  tmp = s->teams->start;
  t_iterate = xmalloc(sizeof(t_team));
  t_iterate = tmp->data;
  while (tmp)
    {
      t_iterate = tmp->data;
      if (strcmp(t_iterate->name, team) == 0)
	{
	  /* free(t_iterate->name); */
	  /* free(t_iterate); */
	  return (0);
	}
      tmp = tmp->next;
    }
  /* free(t_iterate->name); */
  /* free(t_iterate); */
  return (-1);
}

int	cmd_team(t_server *s, t_client *c, const char *cmd)
{
  char		trame[21];
  char		*name;
  t_team	*team;
  
  name = xmalloc((strlen(cmd) - 6) * sizeof(char));
  bzero(trame, 21);
  bzero(name, strlen(cmd) - 6);
  sscanf(cmd, "TEAM %s", name);
  name[strlen(name)] = '\0';
  if (is_a_team(s, name) == 0)
    {
      team = get_team_by_name(s->teams, name);
      if (team->slot_rest >= 1)
	{
	  sprintf(trame, "%d", team->slot_rest);
	  send_data(c->fd, trame);
	  bzero(c->team_name, strlen(name));
	  c->team_name = strdup(name);
	  team->slot_rest--;
	}
      else
	send_data(c->fd, "NO_SLOT_REST\r\n");
    }
  bzero(trame, 21);
  sprintf(trame, "%d - %d\n", s->map->size->width, s->map->size->height);
  send_data(c->fd, trame);
  return (0);
}
