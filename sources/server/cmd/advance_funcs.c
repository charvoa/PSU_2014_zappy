/*
** advance_funcs.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server/cmd_ia
**
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
**
** Started on  Thu May 21 21:08:42 2015 Serge Heitzler
** Last update Sat Jun 27 10:48:53 2015 Audibert Louis
*/

#include "functions.h"

void		adv_up(t_size *size, t_client *client)
{
  if (client->pos->y == 0)
    client->pos->y = size->height - 1;
  else
    client->pos->y--;
}

void		adv_right(t_size *size, t_client *client)
{
  if (client->pos->x == (size->width -1))
    client->pos->x = 0;
  else
    client->pos->x++;
}

void		adv_down(t_size *size, t_client *client)
{
  if (client->pos->y == (size->height -1))
    client->pos->y = 0;
  else
    client->pos->y++;
}

void		adv_left(t_size *size, t_client *client)
{
   if (client->pos->x == 0)
     client->pos->x = size->width - 1;
  else
    client->pos->x--;
}
