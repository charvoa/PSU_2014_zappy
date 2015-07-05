/*
** cmd_team.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
**
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
**
** Started on  Thu May  7 16:30:08 2015 Audibert Louis
** Last update Sun Jul  5 16:42:28 2015 Serge Heitzler
*/

#include "functions.h"

int		is_a_team(t_server *s, char *team)
{
  t_node	*tmp;
  t_team	*t_iterate;

  tmp = s->teams->start;
  t_iterate = tmp->data;
  while (tmp)
    {
      t_iterate = tmp->data;
      if (strcmp(t_iterate->name, team) == 0)
	return (0);
      tmp = tmp->next;
    }
  printf("Team doesnt exist %s\n", team);
  return (-1);
}

int		get_index_to_delete(t_server *s, t_client *c)
{
  int		i;
  t_node	*tmp;
  t_client	*client;

  tmp = s->clients->start;
  i = 0;
  while (tmp)
    {
      client = tmp->data;
      if (client->fd == c->fd)
	return (i);
      tmp = tmp->next;
      i++;
    }
  return (-1);
}

void		do_team(t_server *s, char *name, t_client *c)
{
  char		trame[21];
  t_team	*team;

  team = get_team_by_name(s->teams, name);
  if (team->slot_rest >= 1)
    {
      if (fill_ia_client(s, c, team, name) == 1)
	{
	  c->team_name = strdup(name);
	  cmd_pnw(s, c, NULL, NORMAL);
	}
    }
  else
    send_data(c->fd, "ko\n");
  bzero(trame, 21);
  sprintf(trame, "%d %d\n", s->map->size->width, s->map->size->height);
  send_data(c->fd, trame);
}

int		cmd_team(t_server *s, t_client *c,
			 char *cmd, e_client_type type)
{
  (void)type;
  char		*name;

  name = xmalloc(strlen(cmd) * sizeof(char));
  bzero(name, strlen(cmd));
  sscanf(cmd, "%s", name);
  if (strcmp(name, "GRAPHIC") == 0)
    {
      protocole_graphique(s, c);
      c->type = GUI;
      return (SUCCESS);
    }
  if (is_a_team(s, name) == 0)
    do_team(s, name, c);
  else
    {
      send_data(c->fd, "ko\n");
      remove_at_index(s->clients, get_index_to_delete(s, c));
      return (ERROR);
    }
  c->team_name = strdup(name);
  free(name);
  return (SUCCESS);
}
