/*
** cmd_right.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
**
** Started on  Sun May 17 10:54:26 2015 Serge Heitzler
** Last update Sat Jun 27 14:32:04 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_right(t_server *s, t_client *c, const char *cmd)
{
  (void)s;
  (void)cmd;
  void	(*orientation[4])(t_client *);

  init_orientation(orientation);
  orientation[(c->orientation) % 4](c);
  send_data(c->fd, "ok");
  return (SUCCESS);
}
