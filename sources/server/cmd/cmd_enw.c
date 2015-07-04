/*
** cmd_enw.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue Jun 30 11:10:30 2015 Audibert Louis
** Last update Fri Jul  3 19:47:37 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_enw_normal(t_server *s, t_client *c,
			       t_egg *e, e_client_type type)
{
  int		size_alloc;
  char		*trame;

  size_alloc = (11 + istm(e->id)
		 + istm(e->fd_father)
		 + istm((int)e->pos->x)
		 + istm((int)e->pos->y));
  trame = xmalloc(size_alloc * sizeof(char));
  bzero(trame, size_alloc);
  sprintf(trame, "enw #%d #%d %d %d\n", e->id,
	  e->fd_father, e->pos->x, e->pos->y);
  if (type == GUI)
    send_data_to_gui(s->clients, trame);
  else
    send_data(c->fd, trame);
  free(trame);
  return (SUCCESS);
}

int		cmd_enw_all(t_server *s, t_client *c,
			    e_client_type type)
{
  (void)type;
  t_node	*tmp;
  t_egg		*egg;

  if (s->eggs->length > 0)
    {
      tmp = s->eggs->start;
      while (tmp)
	{
	  egg = tmp->data;
	  cmd_enw_normal(s, c, egg, NORMAL);
	  tmp = tmp->next;
	}
    }
  return (SUCCESS);
}

int		cmd_enw(t_server *s, t_client *c,
			t_egg *e, e_client_type type)
{
 if (type == GUI)
   cmd_enw_normal(s, c, e, type);
 else
   cmd_enw_all(s, c, type);
 return (SUCCESS);
}
