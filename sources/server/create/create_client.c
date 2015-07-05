/*
** create_client.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu May  7 14:50:39 2015 Serge Heitzler
** Last update Sun Jul  5 17:50:21 2015 Serge Heitzler
*/

#include "functions.h"

void		init_orientation(void (*orientation[4])(t_client *))
{
  orientation[0] = &ori_up;
  orientation[1] = &ori_right;
  orientation[2] = &ori_down;
  orientation[3] = &ori_left;
}

void		init_inventory(t_client *c, int food)
{
  c->inventory->food = food;
  c->inventory->linemate = 0;
  c->inventory->deraumere = 0;
  c->inventory->sibur = 0;
  c->inventory->mendiane = 0;
  c->inventory->phiras = 0;
  c->inventory->thystame = 0;
}

void		create_client_from_egg(t_server *s, t_egg *egg, int index)
{
  t_client	*client;

  client = get_client_by_id(s->clients, egg->fd);
  client->pos->x = egg->pos->x;
  client->pos->y = egg->pos->y;
  client->state = ADULT;
  s->map->objects[egg->pos->y][egg->pos->x]->nb_clients++;
  s->map->objects[egg->pos->y][egg->pos->x]->ids =
    add_id(s->map->objects[egg->pos->y][egg->pos->x], egg->fd);
  cmd_eht(egg, s->clients);
  cmd_ebo(egg, s->clients);
  cmd_pnw(s, client, NULL, NORMAL);
  remove_at_index(s->eggs, index);
}

int		create_client(t_server *s, int fd)
{
  t_client	*c;

  c = xmalloc(sizeof(t_client));
  c->fd = fd;
  c->pos = xmalloc(sizeof(t_position));
  c->type = GUI;
  c->state = ADULT;
  c->team_name = strdup("DEFAULT");
  c->inventory = xmalloc(sizeof(t_inventory));
  c->cmds = create_list();
  c->buffer = ring_buffer_create(1024);
  push_back(s->clients, c, PLAYER);
  return (SUCCESS);
}
