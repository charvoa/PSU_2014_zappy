/*
** create_player.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu May  7 10:55:38 2015 Serge Heitzler
** Last update Sat May 16 20:12:29 2015 Serge Heitzler
*/

#include "../../headers/server.h"

void		init_orientation(e_orientation (*orientation[5])(void))
{
  orientations[0] = &ori_up;
  orientations[1] = &ori_right;
  orientations[2] = &ori_down;
  orientations[3] = &ori_left;
  orientations[4] = &ori_none;
}


e_orientation	give_orientation(int i,
				 e_orientation (*orientation[5](void)))
{
  return (orientation[i]);
}

void		init_player(t_player *player,
			    char *team, t_size *size)
{
  int		(*orientation[5])(void);

  init_orientation(orientation);
  player->level = 1;
  player->pos_x = rand() % size->width;
  player->pos_y = rand() % size->height;
  player->orientation = orientation[rand % 4];
  player->inventory = create_list();
}
