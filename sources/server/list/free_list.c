/*
** list.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 17:45:21 2015 Serge Heitzler
** Last update Tue May 26 23:52:54 2015 Serge Heitzler
*/

#include "server.h"

void		free_list(t_list *list)
{
  t_node	*tmp;
  t_node	*del;

  tmp = list->start;
  while (tmp)
    {
      del = tmp;
      tmp = tmp->next;
      free(del->data);
      free(del);
    }
  free(list);
}
