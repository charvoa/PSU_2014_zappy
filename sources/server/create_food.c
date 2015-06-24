/*
** create_food.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Wed Jun 24 10:57:41 2015 Serge Heitzler
** Last update Wed Jun 24 13:57:40 2015 Serge Heitzler
*/

#include "server.h"

int		create_food(t_server *s)
{
  t_food	*food;
  int		x;
  int		y;

  food = xmalloc(sizeof(t_food));
  food->pos = xmalloc(sizeof(t_position));
  x = rand() % s->map->size->width;
  y = rand() % s->map->size->height;
  food->pos->x = x;
  food->pos->y = y;
  push_back(s->map->objects[y][x], food, FOOD);
  return (SUCCESS);
}
