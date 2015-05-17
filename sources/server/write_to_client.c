/*
** write_to_client.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
**
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
**
** Started on  Thu May  7 10:35:54 2015 Audibert Louis
** Last update Sun May 17 11:39:00 2015 Serge Heitzler
*/

#include "server.h"

void	write_to_client(t_server *s, char *str)
{
  if ((write(s->newfd, str, strlen(str))) == -1)
    {
      close(s->newfd);
      printf("Error while reading server response.\n");
      exit(-1);
    }
}
