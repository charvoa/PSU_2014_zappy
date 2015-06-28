/*
** add_or_remove_id.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 26 09:18:17 2015 Audibert Louis
** Last update Sun Jun 28 12:50:25 2015 Audibert Louis
*/

#include "functions.h"

int		remove_from_socket(t_list *list, int id)
{
  t_node	*tmp;
  t_client	*c;
  int		i;

  tmp = list->start;
  i = 0;
  while (tmp)
    {
      c = tmp->data;
      if (c->fd == id)
	{
	  printf("remove_at_index i = %d\n", i);
	  remove_at_index(list, i);
	  return (SUCCESS);
	}
      i++;
      tmp = tmp->next;
    }
  return (ERROR);
}

int		*add_id(t_block *block, int id)
{
  int		*newtab;
  int		i;

  newtab = xmalloc((block->nb_clients + 1) * sizeof(int));
  i = 0;
  if (block->ids[0] != -1)
    {
      while (i <= block->nb_clients)
	{
	  newtab[i] = block->ids[i];
	  i++;
	}
      newtab[i] = id;
    }
  else 
    newtab[0] = id;
  return (newtab);
}

int		*remove_id(t_block *block, int id)
{
  int		*newtab;
  int		i;
  int		j;

  i = 0;
  j = 0;
  printf("block->ids[0] = %d\n", block->ids[0]);
  if (block->ids[0] == id)
    {
      block->ids[0] = -1;
      return (block->ids);
    }
  newtab = xmalloc((block->nb_clients) * sizeof(int));
  while (i < block->nb_clients)
    {
      printf("block->ids[%d] = %d\n", i, block->ids[i]);
      printf("block->nb_clients = %d\n", block->nb_clients);
      if (block->ids[i] == id)
	i++;
      newtab[j] = block->ids[i];
      j++;
      i++;
    }
  return (newtab);
}
