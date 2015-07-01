/*
** width_and_length.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Tue Jun 30 20:40:28 2015 Serge Heitzler
** Last update Wed Jul  1 12:48:34 2015 Serge Heitzler
*/

#include "functions.h"

int	calcul_length(int f_pos_x,
		      int s_pos_x, t_map *map)
{
  if (f_pos_x < s_pos_x)
    return (f_pos_x + (map->size->width - s_pos_x));
  else
    return ((map->size->width - f_pos_x) + s_pos_x);
}

int   	calcul_width(int f_pos_y,
		     int s_pos_y, t_map *map)
{
  if (f_pos_y < s_pos_y)
    return (f_pos_y + (map->size->height - s_pos_y));
  else
    return ((map->size->height - f_pos_y) + s_pos_y);
}

int		get_l(t_map *map, int f_pos_x, int s_pos_x)
{
  int		limit;

  limit = calcul_limit(map->size->width);
  if (abs(f_pos_x - s_pos_x) >= limit)
    return (calcul_length(f_pos_x, s_pos_x, map));
  else
    return (abs(f_pos_x - s_pos_x));
  return (SUCCESS);
}

int		get_w(t_map *map, int f_pos_y, int s_pos_y)
{
  int		limit;

  limit = calcul_limit(map->size->height);
  if (abs(f_pos_y - s_pos_y) >= limit)
    return (calcul_width(f_pos_y, s_pos_y, map));
  else
    return (abs(f_pos_y - s_pos_y));
  return (SUCCESS);
}
