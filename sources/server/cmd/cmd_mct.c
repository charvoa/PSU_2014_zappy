/*
** cmd_mct.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:46 2015 Serge Heitzler
** Last update Sun Jul  5 19:26:02 2015 Audibert Louis
*/

#include "functions.h"

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
		 + istm(b->linemate) + istm(b->deraumere)
		 + istm(b->sibur)
		 + istm(b->mendiane) + istm(b->phiras)
		 + istm(b->thystame));
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
  (void)cmd;
  int		x;
  int	 	y;
  int		size_malloc;
  char		*tmp;

  y = -1;
  while (++y < s->map->size->height)
    {
      x = -1;
      while (++x < s->map->size->width)
	{
	  size_malloc = get_malloc_mct(s->map->objects[y][x], x, y);
	  tmp = xmalloc(sizeof(char) * size_malloc);
	  bzero(tmp, size_malloc);
	  print_mct(s->map->objects[y][x], tmp, x, y);
	  if (type == NORMAL)
	    send_data(c->fd, tmp);
	  else
	    send_data_to_gui(s->clients, tmp);
	  free(tmp);
	}
    }
  return (SUCCESS);
}
