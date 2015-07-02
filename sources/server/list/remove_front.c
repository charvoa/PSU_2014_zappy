/*
** remove_front.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server/list
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue May 26 23:13:32 2015 Serge Heitzler
** Last update Thu Jul  2 16:09:04 2015 Serge Heitzler
*/

#include "server.h"

int		remove_front(t_list *list)
{
  t_node	*tmp;
  t_node	*del;

  if (list->length <= 0)
    return (ERROR);
  if (list->length == 1)
    {
      tmp = list->start;
      del = tmp;
      list->start = NULL;
      list->end = NULL;
    }
  else
    {
      tmp = list->start;
      list->start = tmp->next;
      del = tmp;
    }
  free(del->data);
  free(del);
  list->length--;
  return (SUCCESS);
}
