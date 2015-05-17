/*
** cmd_right.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Sun May 17 10:54:26 2015 Serge Heitzler
** Last update Sun May 17 11:44:59 2015 Serge Heitzler
*/

#include "server.h"

void		cmd_right(t_player *player)
{
  void	(*orientation[4])(t_player *);

  init_orientation(orientation);
  orientation[(player->orientation + 1) % 4](player);
}
