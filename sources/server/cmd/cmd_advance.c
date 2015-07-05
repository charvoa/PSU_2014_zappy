/*
** cmd_advance.c for zappy$ in /home/heitzls/rendu/PSU_2014_zappy/sources/server/cmd_ia
**
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
**
** Started on  Thu May 21 21:03:06 2015 Serge Heitzler
** Last update Sat Jul  4 22:43:53 2015 Serge Heitzler
*/

#include "functions.h"

void		init_advance(void (*advance[5])(t_size *, t_client *))
{
  advance[0] = (void*)&adv_up;
  advance[1] = (void*)&adv_right;
  advance[2] = (void*)&adv_down;
  advance[3] = (void*)&adv_left;
  advance[4] = NULL;
}

int			cmd_advance(t_server *s, t_client *c,
				    char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  void			(*advance[5])(t_size *, t_client *);

  init_advance(advance);
  s->map->objects[c->pos->y][c->pos->x]->ids =
    remove_id(s->map->objects[c->pos->y][c->pos->x], c->fd);
  s->map->objects[c->pos->y][c->pos->x]->nb_clients--;
  advance[c->orientation - 1](s->map->size, c);
  cmd_ppo(s, c, NULL, GUI);
  s->map->objects[c->pos->y][c->pos->x]->ids =
    add_id(s->map->objects[c->pos->y][c->pos->x], c->fd);
  s->map->objects[c->pos->y][c->pos->x]->nb_clients++;
  send_data(c->fd, "ok avance\n");
  return (SUCCESS);
}
