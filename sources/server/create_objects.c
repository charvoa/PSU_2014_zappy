/*
** create_objects.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Wed Jun 24 11:00:23 2015 Serge Heitzler
** Last update Fri Jun 26 20:49:49 2015 Serge Heitzler
*/

#include "server.h"

void		add_objects(t_block *b, int x, int y)
{
  int		r;

  r = (rand() + (rand() * x) + (rand() * y) + x + y) % 8;
  if (r == 0)
    b->food++;
  if (r == 1)
    b->limemate++;
  if (r == 2)
    b->deraumere++;
  if (r == 3)
    b->sibur++;
  if (r == 3)
    b->mendiane++;
  if (r == 5)
    b->phiras++;
  if (r == 6)
    b->thystame++;
}

int		create_objects(t_server *s)
{
  int		x;
  int		y;
  t_block	*b;
  char		*final;
  int		size_malloc;

  b = xmalloc(sizeof(t_block));
  //  b->ids = xmalloc(sizeof(int) * nb_clients); faut il malloc ca ?
  x = rand() % s->map->size->width;
  y = rand() % s->map->size->height;
  b = s->map->objects[y][x];
  add_objects(b, x, y);
  size_malloc = (13 + istm(x) + istm(y) + istm(b->food)
		 + istm(b->limemate) + istm(b->deraumere) + istm(b->sibur)
		 + istm(b->mendiane) + istm(b->phiras) + istm(b->thystame));
  final = xmalloc(sizeof(char) * size_malloc);
  memset(final, 0, size_malloc);
  sprintf(final, "bct %d %d %d %d %d %d %d %d %d\n",
	  x, y, b->food, b->limemate, b->deraumere, b->sibur,
	  b->mendiane, b->phiras, b->thystame);
  send_data_to_gui(s->clients, final);
  return (SUCCESS);
}
