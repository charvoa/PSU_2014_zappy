/*
** create_client.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu May  7 14:50:39 2015 Serge Heitzler
** Last update Mon Jun 22 11:01:49 2015 Audibert Louis
*/

#include "server.h"

void		init_orientation(void (*orientation[4])(t_client *))
{
  orientation[0] = &ori_up;
  orientation[1] = &ori_right;
  orientation[2] = &ori_down;
  orientation[3] = &ori_left;
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
  c->team_name = strdup(team_name);
  c->pos->x = rand() % size->width;
  c->pos->y = rand() % size->height;
  c->inventory = create_list();
  c->cmds = create_list();
  orientation[rand() % 4](c);
  push_back(s->clients, c, PLAYER);
  return (SUCCESS);
}
