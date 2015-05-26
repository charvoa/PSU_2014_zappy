/*
** cmd_advance.c for zappy$ in /home/heitzls/rendu/PSU_2014_zappy/sources/server/cmd_ia
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Thu May 21 21:03:06 2015 Serge Heitzler
** Last update Fri May 22 11:54:29 2015 Serge Heitzler
*/

#include "server.h"

void		init_advance(void (*advance[4])(t_size *, t_client *))
{
  advance[0] = (void*)&adv_up;
  advance[1] = (void*)&adv_right;
  advance[2] = (void*)&adv_down;
  advance[3] = (void*)&adv_left;
}

int			cmd_advance(t_server *server, t_client *client)
{
  void			(*advance[4])(t_size *, t_client *);

  usleep((7 / server->time_action) * 1000);
  init_advance(advance);
  advance[client->orientation](server->map->size, client);
  send_data(client->fd, "ok");
  return (SUCCESS);
}