/*
** cmd_left.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
**
** Started on  Sun May 17 11:30:51 2015 Serge Heitzler
** Last update Sun Jul  5 14:05:06 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_left(t_server *s, t_client *c,
			 char *cmd, e_client_type type)
{
  (void)type;
  (void)s;
  (void)cmd;
  void	(*orientation[4])(t_client *);

  if (c->state == CHILD)
    return (ERROR);
  init_orientation(orientation);
  if (c->orientation == 1)
    orientation[(c->orientation + 2)](c);
  else
    orientation[(c->orientation - 2) % 4](c);
  cmd_ppo(s, c, NULL, GUI);
  send_data(c->fd, "ok");
  return (SUCCESS);
}
