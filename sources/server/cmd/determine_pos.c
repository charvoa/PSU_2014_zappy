/*
** determine_pos.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Tue Jun 23 20:37:51 2015 Serge Heitzler
** Last update Sat Jun 27 14:35:31 2015 Serge Heitzler
*/

#include "functions.h"

int		determine_pos_x(t_client *c, t_size *size, int t, int l)
{
  if (c->orientation == NORD)
    return ((c->pos->x + t) >= 0 ?
	    (c->pos->x + t) % size->width : (size->width + c->pos->x + t));
  if (c->orientation == EST)
    return ((c->pos->x + l) >= 0 ?
	    (c->pos->x + l) % size->width : (size->width + c->pos->x + l));
  if (c->orientation == SUD)
    return ((c->pos->x - t) >= 0 ?
	    (c->pos->x - t) % size->width : (size->width + c->pos->x - t));
  if (c->orientation == OUEST)
    return ((c->pos->x - l) >= 0 ?
	    (c->pos->x - l) % size->width : (size->width + c->pos->x - l));
  return (SUCCESS);
}

int		determine_pos_y(t_client *c, t_size *size, int t, int l)
{
  if (c->orientation == NORD)
    return ((c->pos->y - l) < 0 ?
	    (size->height + c->pos->y - l) : c->pos->y - l);
  if (c->orientation == EST)
    return ((c->pos->y + t) >= 0 ?
	    (c->pos->y + t) % size->height : (size->height + c->pos->y + t));
  if (c->orientation == SUD)
    return ((c->pos->y + l) >= size->height ?
	    (c->pos->y + l) % size->height : c->pos->y + l);
  if (c->orientation == OUEST)
    return ((c->pos->y - t) >= 0 ?
	    (c->pos->y - t) % size->height : (size->height + c->pos->y - t));
  return (SUCCESS);
}
