/*
** xsocket.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/xfuncs
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May  6 13:16:45 2015 Serge Heitzler
** Last update Wed May  6 13:17:10 2015 Serge Heitzler
*/

#include "../../headers/server.h"

int	xsocket(int domain, int type, int protocol)
{
  int	listener;

  if ((listener = socket(domain, type, protocol)) == -1)
    {
      perror("Server-socket() error !");
      exit(1);
    }
  return (listener);
}
