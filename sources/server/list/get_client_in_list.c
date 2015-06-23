/*
** get_client_in_list.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:30:14 2015 Serge Heitzler
** Last update Tue Jun 23 14:06:32 2015 Audibert Louis
*/

#include "server.h"

t_client		*get_client_by_id(t_list *list, int id)
{
  t_node		*tmp;
  t_client		*client;

  tmp = list->start;
  client = xmalloc(sizeof(t_client));
  client = tmp->data;
  printf("length = %zu\n", list->length);
  printf("client->fd = %d\n", client->fd);
  while (tmp && (id != client->fd))
    {
      client = tmp->data;
      printf("client->fd = %d\n", client->fd);
      tmp = tmp->next;
    }
  return (client);
}
