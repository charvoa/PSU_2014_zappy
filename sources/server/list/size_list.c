/*
** size_list.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue May 26 16:13:34 2015 Serge Heitzler
** Last update Tue May 26 19:47:06 2015 Serge Heitzler
*/

#include "server.h"

size_t		size_list(t_list *list)
{
  t_node        *tmp;
  int		i;

  i = 0;
  tmp = list->start;
  while (tmp)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}
