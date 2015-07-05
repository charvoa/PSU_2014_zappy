/*
** cmd_right.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
**
** Started on  Sun May 17 10:54:26 2015 Serge Heitzler
** Last update Sat Jul  4 22:43:56 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_right(t_server *s, t_client *c,
			  char *cmd, e_client_type type)
{
  (void)s;
  (void)cmd;
  (void)type;
  void	(*orientation[4])(t_client *);

  init_orientation(orientation);
  orientation[(c->orientation) % 4](c);
  cmd_ppo(s, c, NULL, GUI);
  send_data(c->fd, "ok");
  return (SUCCESS);
}
