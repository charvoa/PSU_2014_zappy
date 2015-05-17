/*
** create_player.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu May  7 10:55:38 2015 Serge Heitzler
** Last update Sun May 17 11:38:24 2015 Serge Heitzler
*/

#include "../../headers/server.h"

void		init_orientation(void (*orientation[4])(t_player *))
{
  orientation[0] = &ori_up;
  orientation[1] = &ori_right;
  orientation[2] = &ori_down;
  orientation[3] = &ori_left;
}

void		init_player(t_player *player,
			    char *team, t_size *size)
{
  void	(*orientation[4])(t_player *);

  init_orientation(orientation);
  player->level = 1;
  player->team = strdup(team);
  player->pos->x = rand() % size->width;
  player->pos->y = rand() % size->height;
  orientation[rand() % 4](player);
  player->inventory = create_list();
}
