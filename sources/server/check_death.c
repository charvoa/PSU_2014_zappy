/*
** check_death.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 15:59:28 2015 Audibert Louis
** Last update Sat Jun 27 16:37:10 2015 Audibert Louis
*/

#include "functions.h"

int		get_alloc_to_delete(t_server *s)
{
  t_node	*tmp;
  t_client	*c;
  int		i;

  tmp = s->clients->start;
  i = 0;
  while (tmp != NULL)
    {
      c = xmalloc(sizeof(t_client));
      c = tmp->data;
      if (c->inventory->food == 0)
	i++;
      tmp = tmp->next;
    }
  free(c);
  return (i);
}

void		delete_players(t_server *s, int *fds, int len)
{
  int		i;

  i = 0;
  while (i < len)
    {
      remove_at_index(s->clients, fds[i]);
      i++;
    }
  free(fds);
}

void		check_death(t_server *s)
{
  t_node	*tmp;
  t_client	*c;
  int		i;
  int		*delete_fds;

  delete_fds = xmalloc(get_alloc_to_delete(s));
  tmp = s->clients->start;
  i = 0;
  while (tmp != NULL)
    {
      c = xmalloc(sizeof(t_client));
      c = tmp->data;
      if (c->inventory->food == 0)
	{
	  delete_fds[i] = i;
	  i++;
	}
      tmp = tmp->next;
    }
  delete_players(s, delete_fds, i);
}
