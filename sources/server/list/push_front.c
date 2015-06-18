/*
** push_front.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server/list
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue May 26 18:29:37 2015 Serge Heitzler
** Last update Tue May 26 21:13:52 2015 Serge Heitzler
*/

#include "server.h"

int		push_front(t_list *list, void *data, e_node_type type)
{
  t_node	*node;

  node = xmalloc(sizeof(*node));
  node->data = data;
  node->type = type;
  if (list != NULL)
    {
      if (list->start == NULL)
	{
	  list->start = node;
	  list->end = node;
	  node->next = NULL;
	  node->prev = NULL;
	}
      else
	{
	  node->next = list->start;
	  list->start = node;
	  node->prev = NULL;
	}
      list->length++;
      return (SUCCESS);
    }
  return (ERROR);
}
