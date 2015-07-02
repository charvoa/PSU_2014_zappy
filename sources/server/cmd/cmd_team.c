/*
** commands.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
**
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
**
** Started on  Thu May  7 16:30:08 2015 Audibert Louis
** Last update Thu Jul  2 09:48:51 2015 Audibert Louis
*/

#include "functions.h"

int		is_a_team(t_server *s, char *team)
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
	  printf("Team exist %s\n", team);
	  return (0);
	}
      tmp = tmp->next;
    }
  /* free(t_iterate->name); */
  /* free(t_iterate); */
  printf("Team doesnt exist %s\n", team);
  return (-1);
}

int		fill_ia_client(t_server *s, t_client *c, t_team *t, char *n)
{
  void		(*orientation[4])(t_client *);
  char		trame[21];

  init_orientation(orientation);
  orientation[rand() % 4](c);
  c->type = IA;
  c->level = 1;
  c->team_name = strdup(n);
  printf("T1 = %s\n", c->team_name);
  t->slot_rest--;
  if (is_there_an_egg(s->eggs, n, c->fd) == SUCCESS)
    {
      c->state = CHILD;
      init_inventory(c, 10);
      return (0);
    }
  c->state = ADULT;
  c->pos->x = rand() % s->map->size->width;
  c->pos->y = rand() % s->map->size->height;
  s->map->objects[c->pos->y][c->pos->x]->nb_clients++;
  s->map->objects[c->pos->y][c->pos->x]->ids =
    add_id(s->map->objects[c->pos->y][c->pos->x], c->fd);
  init_inventory(c, 10);
  sprintf(trame, "%d", t->slot_rest);
  send_data(c->fd, trame);
  bzero(c->team_name, strlen(n));
  send_data(c->fd, "ok\n");
  return (1);
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

int		cmd_team(t_server *s, t_client *c,
			 char *cmd, e_client_type type)
{
  (void)type;
  char		trame[21];
  char		*name;
  t_team	*team;

  name = xmalloc(strlen(cmd) * sizeof(char));
  bzero(name, strlen(cmd));
  sscanf(cmd, "%s", name);
  if (strcmp(name, "GRAPHIC") == 0)
    protocole_graphique(s, c);
  if (is_a_team(s, name) == 0)
    {
      printf("Im in cmd_team when is_a_team send 0\n");
      team = get_team_by_name(s->teams, name);
      if (team->slot_rest >= 1)
	{
	  if (fill_ia_client(s, c, team, name) == 1)
	    cmd_pnw(s, c, NULL, NORMAL);
	}
      else
	send_data(c->fd, "ko\n");
      bzero(trame, 21);
      sprintf(trame, "%d %d\n", s->map->size->width, s->map->size->height);
      printf("TRAM %s\n", trame);
      send_data(c->fd, trame);
    }
  else
    {
      send_data(c->fd, "ko\n");
      remove_at_index(s->clients, get_index_to_delete(s, c));
      return (ERROR);
    }
  c->team_name = strdup(name);
  printf("T2 = %s\n", c->team_name);
  return (SUCCESS);
}
