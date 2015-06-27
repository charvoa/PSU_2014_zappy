/*
** distances.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Sun May 17 11:39:43 2015 Serge Heitzler
** Last update Sat Jun 27 10:43:12 2015 Audibert Louis
*/

#include "functions.h"

unsigned int	calcul_length(unsigned int f_pos_x,
			      unsigned int s_pos_x, t_map *map)
{
  if (f_pos_x < s_pos_x)
    return (f_pos_x + (map->size->width - s_pos_x));
  else
    return ((map->size->width - f_pos_x) + s_pos_x);
}

unsigned int   	calcul_width(unsigned int f_pos_y,
			     unsigned int s_pos_y, t_map *map)
{
  if (f_pos_y < s_pos_y)
    return (f_pos_y + (map->size->height - s_pos_y));
  else
    return ((map->size->height - f_pos_y) + s_pos_y);
}

float		calcul_distance(int w, int l)
{
  if (w == 0)
    return (l);
  else if (l == 0)
    return (w);
  else
    return (sqrt((w * w) + (l * l)));
}

unsigned int	calcul_limit(unsigned int len)
{
  if (len % 2 == 0)
    return ((unsigned int)(len / 2));
  return ((unsigned int)((len / 2) + 1));
}

float		give_me_distance(t_map *map, t_position *f_pos, t_position *s_pos)
{
  unsigned int	limit;
  unsigned int	l;
  unsigned int	w;

  limit = calcul_limit(map->size->width);
  if ((unsigned int)abs(f_pos->x - s_pos->x) >= limit)
    l = calcul_length(f_pos->x, s_pos->x, map);
  else
    l = abs(f_pos->x - s_pos->x);
  limit = calcul_limit(map->size->height);
  if ((unsigned int)abs(f_pos->y - s_pos->y) >= limit)
    w = calcul_width(f_pos->y, s_pos->y, map);
  else
    w = abs(f_pos->y - s_pos->y);
  return (calcul_distance(w, l));
}
