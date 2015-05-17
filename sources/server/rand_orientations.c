/*
** rand_orientations.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Sat May 16 19:57:54 2015 Serge Heitzler
** Last update Sun May 17 11:26:08 2015 Serge Heitzler
*/

#include "../../headers/server.h"

void		ori_up(t_player *player)
{
  player->orientation = UP;
}

void		ori_right(t_player *player)
{
  player->orientation = RIGHT;
}

void		ori_down(t_player *player)
{
  player->orientation = DOWN;
}

void		ori_left(t_player *player)
{
  player->orientation = LEFT;
}
