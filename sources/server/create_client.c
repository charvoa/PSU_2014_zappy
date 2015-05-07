/*
** create_client.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Thu May  7 14:50:39 2015 Serge Heitzler
** Last update Thu May  7 15:33:33 2015 Serge Heitzler
*/

#include "../../headers/server.h"

void		create_client(t_client *client, int fd,
			    int nbr_players, char *team_name)
{
  client->fd = fd;
  client->nbr_players = nbr_players;
  client->team_name = team_name;
  client->players = create_list();
}
