/*
** determine_pos.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Tue Jun 23 20:37:51 2015 Serge Heitzler
** Last update Wed Jun 24 06:57:47 2015 Serge Heitzler
*/

#include "server.h"

int		determine_pos_x(t_client *c, t_size *size, int t, int l)
{
  (void)size;
  if (c->orientation == UP)
    return ((c->pos->x + t) >= 0 ?
	    (c->pos->x + t) % size->width : (size->width - c->pos->x + t));
  if (c->orientation == RIGHT)
    return ((c->pos->x + l) >= 0 ?
	    (c->pos->x + l) % size->width : (size->width - c->pos->x + l));
  if (c->orientation == DOWN)
    return ((c->pos->x - t) >= 0 ?
	    (c->pos->x - t) % size->width : (size->width - c->pos->x - t));
  if (c->orientation == LEFT)
    return ((c->pos->x - l) % size->width);
  return (SUCCESS);
}

int		determine_pos_y(t_client *c, t_size *size, int t, int l)
{
  (void)size;
  if (c->orientation == UP)
    return ((c->pos->y + l) % size->height);
  if (c->orientation == RIGHT)
    return ((c->pos->y + t) % size->height);
  if (c->orientation == DOWN)
    return ((c->pos->y - l) % size->height);
  if (c->orientation == LEFT)
    return ((c->pos->y - t) % size->height);
  return (SUCCESS);
}
