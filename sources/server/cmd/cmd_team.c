/*
** commands.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 16:30:08 2015 Audibert Louis
** Last update Tue Jun 30 16:53:32 2015 Serge Heitzler
*/

#include "functions.h"

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

int	fill_ia_client(t_server *s, t_client *c, t_team *t, char *n)
{
  void		(*orientation[4])(t_client *);
  char		trame[21];

  init_orientation(orientation);
  orientation[rand() % 4](c);
  c->type = IA;
  c->level = 1;
  c->team_name = strdup(n);
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

int	cmd_team(t_server *s, t_client *c,
		 const char *cmd, e_client_type type)
{
  (void)type;
  char		trame[21];
  char		*name;
  t_team	*team;

  name = xmalloc(strlen(cmd) * sizeof(char));
  bzero(name, strlen(cmd));
  sscanf(cmd, "%s", name);
  if (is_a_team(s, name) == 0)
    {
      team = get_team_by_name(s->teams, name);
      if (team->slot_rest >= 1)
	{
	  if (fill_ia_client(s, c, team, name) == 1)
	    cmd_pnw(s, c, NULL, NORMAL);
	}
      else
	send_data(c->fd, "NO_SLOT_REST\r\n");
      bzero(trame, 21);
      sprintf(trame, "%d %d\n", s->map->size->width, s->map->size->height);
      printf("TRAM %s\n", trame);
      send_data(c->fd, trame);
    }
  else
    send_data(c->fd, "ko\n");
  return (0);
}
