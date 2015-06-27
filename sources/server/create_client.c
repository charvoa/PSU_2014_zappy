/*
** create_client.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu May  7 14:50:39 2015 Serge Heitzler
** Last update Sat Jun 27 10:42:20 2015 Audibert Louis
*/

#include "functions.h"

void		init_orientation(void (*orientation[4])(t_client *))
{
  orientation[0] = &ori_up;
  orientation[1] = &ori_right;
  orientation[2] = &ori_down;
  orientation[3] = &ori_left;
}

void		init_inventory(t_client *c)
{
  c->inventory->food = 10;
  c->inventory->limemate = 0;
  c->inventory->deraumere = 0;
  c->inventory->sibur = 0;
  c->inventory->mendiane = 0;
  c->inventory->phiras = 0;
  c->inventory->thystame = 0;
}

int		create_client(t_server *s, int fd,
			      char *team_name, t_size *size)
{
  void(*orientation[4])(t_client *);
  t_client	*c;

  init_orientation(orientation);
  c = xmalloc(sizeof(t_client));
  c->pos = xmalloc(sizeof(t_position));
  c->fd = fd;
  c->level = 1;
  c->type = IA;
  c->team_name = strdup(team_name);
  c->pos->x = rand() % size->width;
  c->pos->y = rand() % size->height;
  c->inventory = xmalloc(sizeof(t_client));
  init_inventory(c);
  c->cmds = create_list();
  c->buffer = ring_buffer_create(1024);
  printf("buffer created\n");
  orientation[rand() % 4](c);
  push_back(s->clients, c, PLAYER);
  printf("[create_client] - I have created a client with fd [%d]\n", c->fd);
  return (SUCCESS);
}
