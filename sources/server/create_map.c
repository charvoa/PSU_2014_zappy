/*
** create_map.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May  6 19:35:46 2015 Serge Heitzler
** Last update Thu May  7 17:40:34 2015 Serge Heitzler
*/

#include "../../headers/server.h"

char		**init_full_tab(int width, int height)
{
  char		**tab;
  int		y;

  y = 0;
  tab = xmalloc(height * sizeof(char *));
  while (y <= (height - 1))
    {
      tab[y] = xmalloc((width + 1) * sizeof(char));
      memset(tab, 0, width);
      y++;
    }
  tab[y] = NULL;
  return (tab);
}

void		init_map(t_map *map, unsigned int width, unsigned int height)
{
  unsigned int	x;
  unsigned int	y;

  y = 0;
  map = xmalloc(sizeof(t_map));
  map->width = width;
  map->height = height;
  map->objects = xmalloc((width * height) * sizeof(t_list));
  while (y <= (height - 1))
    {
      x = 0;
      map->objects[y] = xmalloc(width * sizeof(t_list));
      while (x <= (width - 1))
      	{
	  map->objects[y][x] = create_list();
      	  x++;
      	}
      map->objects[y][x] = NULL;
      y++;
    }
  map->objects[y] = NULL;
  map->full = init_full_tab(width, height);
}
