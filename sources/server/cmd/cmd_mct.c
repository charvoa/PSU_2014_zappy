/*
** cmd_mct.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:46 2015 Serge Heitzler
** Last update Wed Jul  1 18:43:58 2015 Serge Heitzler
*/

#include "functions.h"

int		number_of_busy_space(t_server *s)
{
  int		busy;
  int		x;
  int		y;

  y = 0;
  busy = 0;
  while (y < s->map->size->height)
    {
      x = 0;
      while (x < s->map->size->width)
	{
	  if (s->map->full[y][x] == '1')
	    busy++;
	  x++;
	}
      y++;
    }
  return (busy);
}

int		get_all_malloc_size(t_server *s)
{
  int		all_malloc_size;
  int		x;
  int		y;

  all_malloc_size = 0;
  y = 0;
  while (y < s->map->size->height)
    {
      x = 0;
      while (x < s->map->size->width)
	{
	  all_malloc_size += get_size_malloc_at_position(s, x, y);
	  x++;
	}
      y++;
    }
  return (all_malloc_size);
}

int		get_malloc_mct(t_block *b, int x, int y)
{
  int		size_malloc;

  size_malloc = (14 + istm(x) + istm(y) + istm(b->food)
		 + istm(b->linemate) + istm(b->deraumere) + istm(b->sibur)
		 + istm(b->mendiane) + istm(b->phiras) + istm(b->thystame));
  return (size_malloc);
}

void		print_mct(t_block *b, char *tmp, int x, int y)
{
  sprintf(tmp, "bct %d %d %d %d %d %d %d %d %d\n", x, y, b->food,
	  b->linemate, b->deraumere, b->sibur,
	  b->mendiane, b->phiras, b->thystame);
}

int		cmd_mct(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  int		x;
  int	 	y;
  t_block	*b;
  int		size_malloc;
  char		*tmp;

  y = -1;
  b = xmalloc(sizeof(t_block));
  while (++y < s->map->size->height)
    {
      x = -1;
      while (++x < s->map->size->width)
	{
	  b = s->map->objects[y][x];
	  size_malloc = get_malloc_mct(b, x, y);
	  tmp = xmalloc(sizeof(char) * size_malloc);
	  bzero(tmp, size_malloc);
	  print_mct(b, tmp, x, y);
	  printf("%s", tmp);
	  send_data(c->fd, tmp);
	  free(tmp);
	}
    }
  return (SUCCESS);
}
