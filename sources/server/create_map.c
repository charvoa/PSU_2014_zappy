/*
** create_map.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May  6 19:35:46 2015 Serge Heitzler
** Last update Thu May  7 13:56:38 2015 Serge Heitzler
*/

#include "../../headers/server.h"

char		**init_full_tab(int height)
{
  char		**tab;
  int		y;

  y = 0;
  tab = xmalloc(height * sizeof(char *));
  while (y <= (height - 1))
    {
      map->objects[y] = xmalloc((width + 1) * sizeof(char));
      memset(map->objects[y], 0, width);
      y++;
    }
  tab[y] = NULL;
  return (tab);
}

void		init_map(t_map *map, int width, int height)
{
  int		x;
  int		y;

  y = 0;
  map = xmalloc(sizeof(t_map));
  map->width = width;
  map->height = height;
  while (y <= (height - 1))
    {
      x = 0;
      while (x <= (width - 1))
	{
	  map->objects[x][y] = create_list();
	  x++;
	}
      y++;
    }
  map->full = init_full_tab(height);
}
