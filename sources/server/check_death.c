/*
** check_death.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 15:59:28 2015 Audibert Louis
** Last update Sat Jun 27 16:09:59 2015 Audibert Louis
*/

#include "functions.h"

void		check_death(t_server *s)
{
  t_node	*tmp;
  t_client	*c;
  int		i;

  tmp = s->clients->start;
  i = 0;
  if (tmp != NULL)
    {
      c = xmalloc(sizeof(t_client));
      c = tmp->data;
      if (c->inventory->food == 0)
	{
	  send_data(c->fd, "mort\n");
	  close(c->fd);
	  remove_at_index(s->clients, i);
	}
      i++;
      tmp = tmp->next;
    }
}
