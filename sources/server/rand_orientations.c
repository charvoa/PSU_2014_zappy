/*
** rand_orientations.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Sat May 16 19:57:54 2015 Serge Heitzler
** Last update Thu May 21 22:07:00 2015 Serge Heitzler
*/

#include "server.h"

void		ori_up(t_client *client)
{
  client->orientation = UP;
}

void		ori_right(t_client *client)
{
  client->orientation = RIGHT;
}

void		ori_down(t_client *client)
{
  client->orientation = DOWN;
}

void		ori_left(t_client *client)
{
  client->orientation = LEFT;
}
