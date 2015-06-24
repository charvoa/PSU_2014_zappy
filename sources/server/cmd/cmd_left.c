/*
** cmd_left.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
**
** Started on  Sun May 17 11:30:51 2015 Serge Heitzler
** Last update Wed Jun 24 10:47:24 2015 Audibert Louis
*/

#include "server.h"

int		cmd_left(t_server *s, t_client *c, const char *cmd)
{
  (void)s;
  (void)cmd;
  void	(*orientation[4])(t_client *);

  init_orientation(orientation);
  if (c->orientation == 0)
    orientation[(c->orientation + 3)](c);
  else
    orientation[(c->orientation - 1) % 4](c);
  printf("c->fd in cmd_left = %d\n", c->fd);
  send_data(c->fd, "ok");
  return (SUCCESS);
}
