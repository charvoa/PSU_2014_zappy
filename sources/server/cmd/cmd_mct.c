/*
** cmd_mct.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:46 2015 Serge Heitzler
** Last update Wed Jul  1 10:28:59 2015 Serge Heitzler
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

int		cmd_mct(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  int		x;
  int	 	y;
  int		busy;
  char		*tmp;
  char		*final;

  busy = number_of_busy_space(s);
  printf("[MCT]-BUSY = %d\n", busy);
  final = xmalloc(sizeof(char) * ((9 * busy) + get_all_malloc_size(s)));
  memset(final, 0, ((9 * busy) + get_all_malloc_size(s)));
  y = 0;
  while (y < s->map->size->height)
    {
      x = 0;
      while (x < s->map->size->width)
	{
	  tmp = show_items_at_position(s, x, y);
	  sprintf(final, "%sbct %d %d {%s}\n", final, x, y, tmp);
	  free(tmp);
	  x++;
	}
      y++;
    }
  send_data(c->fd, final);
  return (SUCCESS);
}
