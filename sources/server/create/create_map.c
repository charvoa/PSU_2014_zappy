/*
** create_map.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May  6 19:35:46 2015 Serge Heitzler
** Last update Sun Jul  5 19:39:42 2015 Audibert Louis
*/

#include "functions.h"

void		init_block(t_block *b)
{
  b->ids = xmalloc(sizeof(int));
  b->ids[0] = -1;
  b->food = 0;
  b->linemate = 0;
  b->deraumere = 0;
  b->sibur = 0;
  b->mendiane = 0;
  b->phiras = 0;
  b->thystame = 0;
  b->nb_clients = 0;
}

void		init_map(t_server *s, unsigned int width,
			 unsigned int height)
{
  unsigned int	x;
  unsigned int	y;

  y = 0;
  s->map = xmalloc(sizeof(*(s->map)));
  s->map->size = xmalloc(sizeof(*(s->map->size)));
  s->map->size->width = width;
  s->map->size->height = height;
  s->map->objects = xmalloc((width * height) * sizeof(t_block));
  while (y <= (height - 1))
    {
      x = 0;
      s->map->objects[y] = xmalloc(width * sizeof(t_block));
      while (x <= (width - 1))
      	{
	  s->map->objects[y][x] = xmalloc(sizeof(t_block));
	  s->map->objects[y][x]->ids = NULL;
	  init_block(s->map->objects[y][x]);
      	  x++;
      	}
      s->map->objects[y][x] = NULL;
      y++;
    }
  s->map->objects[y] = NULL;
}

void		launch_init_map(t_server *s)
{
  if (s->map_set[0] != 0 && s->map_set[1] != 0)
    init_map(s, s->map_set[1], s->map_set[0]);
  else if (s->map_set[0] != 0 && s->map_set[1] == 0)
    init_map(s, s->map_set[1], 7);
  else if (s->map_set[0] == 0 && s->map_set[1] != 0)
    init_map(s, 7, s->map_set[0]);
  else
    init_map(s, 7, 7);
}
