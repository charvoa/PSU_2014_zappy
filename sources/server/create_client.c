/*
** create_client.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu May  7 14:50:39 2015 Serge Heitzler
** Last update Sun Jun 28 12:23:18 2015 Serge Heitzler
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
  c->inventory->linemate = 1;
  c->inventory->deraumere = 0;
  c->inventory->sibur = 0;
  c->inventory->mendiane = 0;
  c->inventory->phiras = 0;
  c->inventory->thystame = 0;
}

int		create_client(t_server *s, int fd)
{
  t_client	*c;

  c = xmalloc(sizeof(t_client));
  c->fd = fd;
  c->pos = xmalloc(sizeof(t_position));
  c->type = IA;
  c->team_name = strdup("DEFAULT");
  c->inventory = xmalloc(sizeof(t_client));
  c->cmds = create_list();
  c->buffer = ring_buffer_create(1024);
  push_back(s->clients, c, PLAYER);
  return (SUCCESS);
}
