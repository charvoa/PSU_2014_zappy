/*
** add_in_list.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 16:42:37 2015 Serge Heitzler
** Last update Sun May  3 16:43:06 2015 Serge Heitzler
*/

#include "../../headers/server.h"

void		add_node(t_list *list, t_node *node)
{
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
    }
}

void		push_in_list(t_list *list, void *data)
{
  t_node	*node;

  node = xmalloc(sizeof(*node));
  node->data = data;
  add_node(list, node);
}