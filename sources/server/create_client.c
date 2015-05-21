/*
** create_client.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu May  7 14:50:39 2015 Serge Heitzler
** Last update Thu May 21 20:40:28 2015 Serge Heitzler
*/

#include "server.h"

void		init_orientation(void (*orientation[4])(t_client *))
{
  orientation[0] = &ori_up;
  orientation[1] = &ori_right;
  orientation[2] = &ori_down;
  orientation[3] = &ori_left;
}

void		create_client(t_client *client, int fd,
			      char *team_name, t_size *size)
{
  void(*orientation[4])(t_client *);

  init_orientation(orientation);
  client->fd = fd;
  client->level = 1;
  client->team_name = strdup(team_name);
  client->pos->x = rand() % size->width;
  client->pos->y = rand() % size->height;
  client->inventory = create_list();
  orientation[rand() % 4](client);
}
