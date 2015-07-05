/*
** get_client_in_list.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:30:14 2015 Serge Heitzler
** Last update Sun Jul  5 10:28:49 2015 Serge Heitzler
*/

#include "server.h"

t_client		*get_client_by_id(t_list *list, int id)
{
  t_node		*tmp;
  t_client		*client;

  tmp = list->start;
  if (list->length > 0)
    {
      while (tmp)
	{
	  client = tmp->data;
	  if (id == client->fd)
	    return (client);
	  tmp = tmp->next;
	}
    }
  return (NULL);
}

int			remove_client_by_id(t_list *list, int id)
{
  t_node		*tmp;
  t_client		*client;
  int			i;

  i = 0;
  tmp = list->start;
  client = tmp->data;
  while (tmp)
    {
      client = tmp->data;
      if (id == client->fd)
	{
	  remove_at_index(list, i);
	  return (SUCCESS);
	}
      i++;
      tmp = tmp->next;
    }
  return (ERROR);  
}
