/*
** create_map.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May  6 19:35:46 2015 Serge Heitzler
** Last update Sat Jun 27 10:42:53 2015 Audibert Louis
*/

#include "functions.h"

char		**init_full_tab(int width, int height)
{
  char		**tab;
  int		y;

  y = 0;
  tab = xmalloc((height + 1) * sizeof(char *));
  while (y <= (height - 1))
    {
      tab[y] = xmalloc((width + 1) * sizeof(char));
      memset(tab[y], 0, width + 1);
      y++;
    }
  tab[y] = NULL;
  return (tab);
}

void		init_map(t_server *s, unsigned int width, unsigned int height)
{
  unsigned int	x;
  unsigned int	y;

  y = 0;
  s->map = xmalloc(sizeof(*(s->map)));
  s->map->size = xmalloc(sizeof(*(s->map->size)));
  s->map->size->width = width;
  s->map->size->height = height;
  s->map->objects = xmalloc((width * height) * sizeof(t_block));
  while (y <= (height - 1))
    {
      x = 0;
      s->map->objects[y] = xmalloc(width * sizeof(t_block));
      while (x <= (width - 1))
      	{
	  s->map->objects[y][x] = xmalloc(sizeof(t_block));
	  s->map->objects[y][x]->ids = NULL;
	  s->map->objects[y][x]->nb_clients = 0;
      	  x++;
      	}
      s->map->objects[y][x] = NULL;
      y++;
    }
  s->map->objects[y] = NULL;
  s->map->full = init_full_tab(width, height);
}
