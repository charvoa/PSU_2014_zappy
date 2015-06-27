/*
** cmd_advance.c for zappy$ in /home/heitzls/rendu/PSU_2014_zappy/sources/server/cmd_ia
**
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
**
** Started on  Thu May 21 21:03:06 2015 Serge Heitzler
** Last update Sat Jun 27 10:57:19 2015 Audibert Louis
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

int			cmd_advance(t_server *s,
				    t_client *c, const char *cmd)
{
  (void)cmd;
  void			(*advance[5])(t_size *, t_client *);

  init_advance(advance);
  advance[c->orientation](s->map->size, c);
  send_data(c->fd, "ok");
  return (SUCCESS);
}
