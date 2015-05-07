/*
** xfonc.c for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:24:41 2015 Nicolas Charvoz
** Last update Thu May  7 14:19:17 2015 Audibert Louis
*/

#include "../../headers/server.h"

int	xlisten(int sockfd, int backlog)
{
  if (listen(sockfd, backlog) == -1)
    {
      perror("Server-listen() error !");
      exit(1);
    }
  printf("Server-listen() is OK ..\n");
  return (0);
}
