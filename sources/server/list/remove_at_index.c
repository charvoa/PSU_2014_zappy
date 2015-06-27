/*
** remove_at_index.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue May 26 23:55:47 2015 Serge Heitzler
** Last update Sat Jun 27 14:12:30 2015 Serge Heitzler
*/

#include "functions.h"

int		is_special(t_list *list, int index)
{
  if (index == 0)
    {
      remove_front(list);
      return (YES);
    }
  if (index == list->length - 1)
    {
      remove_back(list);
      return (YES);
    }
  return (NO);
}

int		remove_at_index(t_list *list, int index)
{
  t_node	*tmp;
  t_node	*del;
  int		i;

  if (index > list->length - 1)
    return (ERROR);
  if (is_special(list, index) == YES)
    return (SUCCESS);
  i = 0;
  tmp = list->start;
  while (i < index)
    {
      tmp = tmp->next;      
      i++;
    }
  del = tmp;
  free(del->data);
  free(del);
  list->length--;
  return (SUCCESS);
}
