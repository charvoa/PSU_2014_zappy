/*
** determine_pos.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Tue Jun 23 20:37:51 2015 Serge Heitzler
** Last update Tue Jun 23 20:38:11 2015 Serge Heitzler
*/

#include "server.h"

int		determine_pos_x(t_client *c, t_size *size, int t, int l)
{
  (void)size;
  if (c->orientation == UP)
    return (c->pos->x + t);
  if (c->orientation == RIGHT)
    return (c->pos->x + l);
  if (c->orientation == DOWN)
    return (c->pos->x - t);
  if (c->orientation == LEFT)
    return (c->pos->x - l);
  return (SUCCESS);
}

int		determine_pos_y(t_client *c, t_size *size, int t, int l)
{
  (void)size;
  if (c->orientation == UP)
    return (c->pos->y + l);
  if (c->orientation == RIGHT)
    return (c->pos->y + t);
  if (c->orientation == DOWN)
    return (c->pos->y - l);
  if (c->orientation == LEFT)
    return (c->pos->y - t);
  return (SUCCESS);
}
