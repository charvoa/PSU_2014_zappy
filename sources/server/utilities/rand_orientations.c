/*
** rand_orientations.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Sat May 16 19:57:54 2015 Serge Heitzler
** Last update Sat Jun 27 14:22:40 2015 Serge Heitzler
*/

#include "functions.h"

void		ori_up(t_client *client)
{
  client->orientation = NORD;
}

void		ori_right(t_client *client)
{
  client->orientation = EST;
}

void		ori_down(t_client *client)
{
  client->orientation = SUD;
}

void		ori_left(t_client *client)
{
  client->orientation = OUEST;
}
