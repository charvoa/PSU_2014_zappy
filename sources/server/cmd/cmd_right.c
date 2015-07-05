/*
** cmd_right.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
**
** Started on  Sun May 17 10:54:26 2015 Serge Heitzler
** Last update Sun Jul  5 14:09:46 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_right(t_server *s, t_client *c,
			  char *cmd, e_client_type type)
{
  (void)s;
  (void)cmd;
  (void)type;
  void	(*orientation[4])(t_client *);

  if (c->state == CHILD)
    return (ERROR);
  init_orientation(orientation);
  orientation[(c->orientation) % 4](c);
  cmd_ppo(s, c, NULL, GUI);
  send_data(c->fd, "ok");
  return (SUCCESS);
}
