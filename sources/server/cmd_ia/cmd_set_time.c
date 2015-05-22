/*
** cmd_set_time.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server/cmd_ia
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Fri May 22 11:14:21 2015 Serge Heitzler
** Last update Fri May 22 11:57:39 2015 Serge Heitzler
*/

#include "server.h"

int		cmd_set_time(t_server *server,
			     t_client *client, const char *cmd)
{
  char		*final;
  char		value[6];

  memset(value, 0, 6);
  sscanf(cmd, "sst %s", value);
  server->time_action = atoi(value);
  final = xmalloc(sizeof(char) *
		  (5 + strlen(value)));
  memset(final, 0, 5 + strlen(value));
  sprintf(final, "sgt %s\n", value);
  send_data(client->fd, final);
  return (SUCCESS);
}
