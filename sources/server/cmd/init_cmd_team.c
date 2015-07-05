/*
** init_cmd_team.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu Jul  2 11:21:57 2015 Audibert Louis
** Last update Sun Jul  5 19:21:16 2015 Audibert Louis
*/

#include "functions.h"

void		init_fill_ia_client(void (*orientation[4])(t_client *),
				    t_client *c, t_team *t, char *n)
{
  init_orientation(orientation);
  orientation[rand() % 4](c);
  c->type = IA;
  c->level = 1;
  c->team_name = strdup(n);
  t->slot_rest--;
}

int		fill_ia_client(t_server *s, t_client *c, t_team *t,
			       char *n)
{
  void		(*orientation[4])(t_client *);
  char		trame[21];

  init_fill_ia_client(orientation, c, t, n);
  sprintf(trame, "%d", t->slot_rest);
  send_data(c->fd, trame);
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
  bzero(c->team_name, strlen(n));
  return (1);
}
