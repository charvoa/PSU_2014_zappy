/*
** distances.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Sun May 17 11:39:43 2015 Serge Heitzler
** Last update Sun Jul  5 19:44:23 2015 Audibert Louis
*/

#include "functions.h"

float		calcul_distance(int w, int l)
{
  if (w == 0)
    return (l);
  else if (l == 0)
    return (w);
  else
    return (sqrt((w * w) + (l * l)));
}

int	calcul_limit(int len)
{
  if (len % 2 == 0)
    return ((len / 2));
  return (((len / 2) + 1));
}

float		give_me_distance(t_map *map, t_position *f_pos,
				 t_position *s_pos)
{
  int	limit;
  int	l;
  int	w;

  limit = calcul_limit(map->size->width);
  if (abs(f_pos->x - s_pos->x) >= limit)
    l = calcul_length(f_pos->x, s_pos->x, map);
  else
    l = abs(f_pos->x - s_pos->x);
  limit = calcul_limit(map->size->height);
  if (abs(f_pos->y - s_pos->y) >= limit)
    w = calcul_width(f_pos->y, s_pos->y, map);
  else
    w = abs(f_pos->y - s_pos->y);
  return (calcul_distance(w, l));
}
