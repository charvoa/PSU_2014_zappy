/*
** create_rock.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Wed Jun 24 11:57:49 2015 Serge Heitzler
** Last update Sat Jul  4 15:11:02 2015 Audibert Louis
*/

#include "functions.h"

int		create_rock(t_server *s)
{
  int		x;
  int		y;
  int		r;

  x = rand() % s->map->size->width;
  y = rand() % s->map->size->height;
  r = (rand() + (rand() * x) + (rand() * y) + x + y) % 6;
  s->map->objects[x][y]->linemate++;
  if (r == 0)
    s->map->objects[x][y]->linemate++;
  if (r == 1)
    s->map->objects[x][y]->deraumere++;
  if (r == 2)
    s->map->objects[x][y]->sibur++;
  if (r == 3)
    s->map->objects[x][y]->mendiane++;
  if (r == 4)
    s->map->objects[x][y]->phiras++;
  if (r == 5)
    s->map->objects[x][y]->thystame++;
  return (SUCCESS);
}
