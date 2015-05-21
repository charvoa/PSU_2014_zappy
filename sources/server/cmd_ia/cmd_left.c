/*
** cmd_left.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Sun May 17 11:30:51 2015 Serge Heitzler
** Last update Thu May 21 21:46:34 2015 Serge Heitzler
*/

#include "server.h"

void		cmd_left(t_server *server, t_client *client)
{
  void	(*orientation[4])(t_client *);

  usleep((7 / server->time_action) * 1000);
  init_orientation(orientation);
  if (client->orientation == 0)
    orientation[(client->orientation + 3)](client);
  else
    orientation[(client->orientation - 1) % 4](client);
  send_data(client->fd, "ok");
}
