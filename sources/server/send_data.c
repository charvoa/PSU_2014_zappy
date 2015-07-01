/*
** send_data.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server/cmd_ia
**
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
**
** Started on  Thu May 21 20:04:00 2015 Serge Heitzler
** Last update Wed Jul  1 12:54:48 2015 Serge Heitzler
*/

#include "functions.h"

int		send_data(int socket, char *buffer)
{
  int		n;
  size_t	len;

  len = strlen(buffer);
  if ((n = write(socket, buffer, len)) == ERROR)
    {
      perror(RED "Error on send\n" RESET);
      return (ERROR);
    }
  return (n);
}

int		send_data_to_gui(t_list *clients, char *msg)
{
  t_node *tmp;
  t_client *client;

  tmp = clients->start;
  client = xmalloc(sizeof(t_client));
  client = tmp->data;
  while (tmp)
    {
      client = tmp->data;
      if (client->type == GUI)
	send_data(client->fd, msg);
      tmp = tmp->next;
    }
  return (0);
}
