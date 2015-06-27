/*
** create_food.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Wed Jun 24 10:57:41 2015 Serge Heitzler
** Last update Sat Jun 27 10:42:49 2015 Audibert Louis
*/

#include "functions.h"

int		create_food(t_server *s)
{
  int		x;
  int		y;

  x = rand() % s->map->size->width;
  y = rand() % s->map->size->height;
  s->map->objects[y][x]->food++;
  return (SUCCESS);
}
