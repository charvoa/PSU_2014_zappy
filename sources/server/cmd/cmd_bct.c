/*
** cmd_bct.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:20 2015 Serge Heitzler
** Last update Sun Jul  5 19:39:00 2015 Audibert Louis
*/

#include "functions.h"

int		get_size_malloc_bct(t_block *b, int x, int y)
{
  int		size_malloc;

  size_malloc = (14 + istm(x) + istm(y) + istm(b->food)
		 + istm(b->linemate) + istm(b->deraumere) + istm(b->sibur)
		 + istm(b->mendiane) + istm(b->phiras) + istm(b->thystame));
  return (size_malloc);
}

char		*get_final_bct(t_block *b, int size_malloc, int x,
			       int y)
{
  char		*final;

  final = malloc_and_memset(size_malloc);
  sprintf(final, "bct %d %d %d %d %d %d %d %d %d\n",
	  x, y, b->food, b->linemate, b->deraumere, b->sibur,
	  b->mendiane, b->phiras, b->thystame);
  return (final);
}

int		cmd_bct(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  int		*x;
  int		*y;
  t_block	*b;
  char		*final;
  int		size_malloc;

  b = xmalloc(sizeof(t_block));
  x = xmalloc(sizeof(int));
  y = xmalloc(sizeof(int));
  if (type == GUI)
    {
      *x = c->pos->x;
      *y = c->pos->y;
    }
  else
    sscanf(cmd, "bct %d %d", x, y);
  b = s->map->objects[*y][*x];
  size_malloc = get_size_malloc_bct(b, *x, *y);
  final = get_final_bct(b, size_malloc, *x, *y);
  if (type == GUI)
    send_data_to_gui(s->clients, final);
  else
    send_data(c->fd, final);
  free(final);
  return (SUCCESS);
}
