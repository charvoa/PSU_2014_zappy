/*
** create_list.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue May 26 16:17:21 2015 Serge Heitzler
** Last update Tue May 26 16:17:48 2015 Serge Heitzler
*/

#include "server.h"

t_list		*create_list()
{
  t_list	*list;

  list = xmalloc(sizeof(*list));
  if (list != NULL)
    {
      list->length = 0;
      list->start = NULL;
      list->end = NULL;
    }
  return (list);
}
