/*
** add_or_remove_id.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 26 09:18:17 2015 Audibert Louis
** Last update Fri Jun 26 09:31:19 2015 Audibert Louis
*/

#include "server.h"

int	*add_id(t_block *block, int id)
{
  int	*newtab;
  int	i;

  newtab = xmalloc((block->nb_clients + 1) * sizeof(char));
  i = 0;
  while (i <= nb->clients)
    {
      newtab[i] = block->ids[i];
      i++;
    }
  newtab[i] = id;
  return (newtab);
}

int	*remove_id(t_block *block, int id)
{
  int	*newtab;
  int	i;
  int	j;
  
  newtab = xmalloc((block->nb_clients - 1) * sizeof(char));
  i = 0;
  j = 0;
  while (i < nb_clients)
    {
      if (block->ids[i] == id)
	i++;
      newtab[j] = block->ids[i];
      j++;
      i++;
    }
  return (newtab);
}
