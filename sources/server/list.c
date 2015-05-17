/*
** list.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 17:45:21 2015 Serge Heitzler
** Last update Sun May 17 11:39:38 2015 Serge Heitzler
*/

#include "server.h"

void            show_list(t_list *list)
{
  t_node        *tmp;
  int		i;

  i = 0;
  tmp = list->start;
  printf("--*--\n[list length] = %zu\n--*--\n", list->length);
  while (tmp)
    {
      printf("[item n°%d] = %p [ADRESS]\n", i, tmp->data);
      tmp = tmp->next;
      i++;
    }
}

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

void		free_my_list(t_list *list)
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
