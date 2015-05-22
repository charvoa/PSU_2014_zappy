/*
** cmd_right.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Sun May 17 10:54:26 2015 Serge Heitzler
** Last update Fri May 22 11:54:44 2015 Serge Heitzler
*/

#include "server.h"

int		cmd_right(t_server *server, t_client *client)
{
  void	(*orientation[4])(t_client *);

  usleep((7 / server->time_action) * 1000);
  init_orientation(orientation);
  orientation[(client->orientation + 1) % 4](client);
  send_data(client->fd, "ok");
  return (SUCCESS);
}
