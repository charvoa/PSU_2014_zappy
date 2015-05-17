/*
** cmd_left.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Sun May 17 11:30:51 2015 Serge Heitzler
** Last update Sun May 17 11:43:33 2015 Serge Heitzler
*/

#include "server.h"

void		cmd_left(t_player *player)
{
  void	(*orientation[4])(t_player *);

  init_orientation(orientation);
  if (player->orientation == 0)
    orientation[(player->orientation + 3)](player);
  else
    orientation[(player->orientation - 1) % 4](player);
}
