/*
** xbind.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/xfuncs
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May  6 13:19:02 2015 Serge Heitzler
** Last update Wed May  6 13:19:16 2015 Serge Heitzler
*/

#include "../../headers/server.h"

void	xbind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  if (bind(sockfd, addr, addrlen) == -1)
    {
      perror("Server-bind() error !");
      exit(1);
    }
}
