/*
** create_food.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Wed Jun 24 10:57:41 2015 Serge Heitzler
** Last update Fri Jul  3 11:18:57 2015 Audibert Louis
*/

#include "functions.h"

int		create_food(t_server *s)
{
  int		x;
  int		y;
  int		allmap;
  int		i;

  allmap = s->map->size->width * s->map->size->height;
  allmap = allmap / 4;
  i = 0;
  while (i <= allmap)
    {
      x = rand() % s->map->size->width;
      y = rand() % s->map->size->height;
      s->map->objects[y][x]->food++;
      i++;
    }
  return (SUCCESS);
}
