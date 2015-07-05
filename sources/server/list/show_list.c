/*
** show_list.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue May 26 16:18:32 2015 Serge Heitzler
** Last update Sun Jul  5 19:40:59 2015 Audibert Louis
*/

#include "server.h"

void            show_list(t_list *list)
{
  t_node        *tmp;
  int		i;

  i = 0;
  tmp = list->start;
  while (tmp)
    {
      printf("[item n°%d] = %p [ADRESS]\n", i, tmp->data);
      tmp = tmp->next;
      i++;
    }
}
