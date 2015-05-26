/*
** get_node_at_index.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server/list
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue May 26 19:15:15 2015 Serge Heitzler
** Last update Tue May 26 19:46:03 2015 Serge Heitzler
*/

#include "server.h"

t_node		*get_node_at_index(t_list *list, size_t index)
{
  t_node        *tmp;
  size_t       	i;

  i = 1;
  tmp = list->start;
  while (i < index)
    {
      tmp = tmp->next;
      i++;
    }
  return (tmp);
}
