/*
** push_at.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server/list
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue May 26 18:33:20 2015 Serge Heitzler
** Last update Tue May 26 23:55:04 2015 Serge Heitzler
*/

#include "server.h"

/* Possible memory leak dans cette fonction, node et tmp pas free. */
int		push_at_index(t_list *list, void *data, e_node_type type, size_t index)
{
  t_node	*node;
  t_node	*tmp;

  node = xmalloc(sizeof(*node));
  node->data = data;
  node->type = type;
  if (list != NULL && index > 0 && index <= (size_list(list)))
    {
      tmp = get_node_at_index(list, index);
      if (tmp->next == NULL)
	{
	  node->prev = tmp->prev;
	  node->next = tmp;
	}
      else if (tmp == list->start)
	push_front(list, data, type);
      else
	{
	  node->prev = tmp->prev;
	  node->next = tmp;
	}
      list->length++;
      return (SUCCESS);
    }
  return (ERROR);
}
