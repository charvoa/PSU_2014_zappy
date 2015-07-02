/*
** add_in_list.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 16:42:37 2015 Serge Heitzler
** Last update Thu Jul  2 16:32:04 2015 Serge Heitzler
*/

#include "server.h"

int		push_back(t_list *list, void *data, e_node_type type)
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
	  list->end->next = node;
	  node->prev = list->end;
	  node->next = NULL;
	  list->end = node;
	}
      list->length++;
      return (SUCCESS);
    }
  return (ERROR);
}
