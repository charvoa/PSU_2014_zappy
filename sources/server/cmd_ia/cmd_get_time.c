/*
** cmd_get_time.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server/cmd_ia
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Fri May 22 11:14:47 2015 Serge Heitzler
** Last update Fri May 22 11:57:52 2015 Serge Heitzler
*/

#include "server.h"

int		cmd_get_time(t_server *server, t_client *client)
{
  char		*final;

  final = xmalloc(sizeof(char) *
		  (5 + int_size_to_malloc(server->time_action)));
  memset(final, 0, 5 + int_size_to_malloc(server->time_action));
  sprintf(final, "sgt %d\n", server->time_action);
  send_data(client->fd, final);
  return (SUCCESS);
}
