/*
** create_rock.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Wed Jun 24 11:57:49 2015 Serge Heitzler
** Last update Wed Jun 24 14:20:47 2015 Serge Heitzler
*/

#include "server.h"

e_rock_type	create_rock_type(int x, int y)
{
  int		r;

  r = (rand() + (rand() * x) + (rand() * y) + x + y) % 6;
  if (r == 0)
    return (LIMEMATE);
  if (r == 1)
    return (DERAUMERE);
  if (r == 2)
    return (SIBUR);
  if (r == 3)
    return (MENDIANE);
  if (r == 4)
    return (PHIRAS);
  if (r == 5)
    return (THYSTAME);
  return (LIMEMATE);
}

int		create_rock(t_server *s)
{
  t_rock	*rock;
  e_rock_type	type;
  int		x;
  int		y;

  rock = xmalloc(sizeof(t_rock));
  rock->pos = xmalloc(sizeof(t_position));
  x = rand() % s->map->size->width;
  y = rand() % s->map->size->height;
  rock->pos->x = x;
  rock->pos->y = y;
  type = create_rock_type(x, y);
  push_back(s->map->objects[y][x], rock, type);
  return (SUCCESS);
}
