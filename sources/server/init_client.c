/*
** init_client.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu May  7 10:41:09 2015 Serge Heitzler
** Last update Thu May  7 10:55:17 2015 Serge Heitzler
*/

#include "../../headers/server.h"

void		init_client(t_client *client, int fd,
			    int nbr_playersn, char *team_name)
{
  client->fd = fd;
  client->nbr_players = nbr_players;
  client->team_name = team_name;
  client->players = create_list();
}
