/*
** xfonc.c for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:24:41 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:13:53 2015 Nicolas Charvoz
*/

#include "server.h"

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

void	xbind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  if (bind(sockfd, addr, addrlen) == -1)
    {
      perror("Server-bind() error !");
      exit(1);
    }
}

void	xlisten(int sockfd, int backlog)
{
  if (listen(sockfd, backlog) == -1)
    {
      perror("Server-listen() error !");
      exit(1);
    }
  printf("Server-listen() is OK ..\n");
}
