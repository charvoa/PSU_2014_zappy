/*
** cmd_enw.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue Jun 30 11:10:30 2015 Audibert Louis
** Last update Tue Jun 30 14:00:41 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_enw(t_server *s, t_client *c,
			e_client_type type, int id)
{
  int		size_alloc;
  char		*trame;

  size_alloc = (11 + istm(id)
		 + istm(c->fd)
		 + istm((int)c->pos->x)
		 + istm((int)c->pos->y));
  trame = xmalloc(size_alloc * sizeof(char));
  bzero(trame, size_alloc);
  sprintf(trame, "enw #%d #%d %d %d\n", id, c->fd, c->pos->x, c->pos->y);
  printf("%s", trame);
  if (type == GUI)
    send_data_to_gui(s->clients, trame);
  /* else */
  /*   send_data(id, trame); */
  return (SUCCESS);
}
