/*
** send_data.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server/cmd_ia
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Thu May 21 20:04:00 2015 Serge Heitzler
** Last update Thu May 21 20:04:47 2015 Serge Heitzler
*/

#include "server.h"

int		send_data(int socket, const char *buffer)
{
  int		n;
  size_t	len;

  len = strlen(buffer);
  if ((n = write(socket, buffer, len)) == ERROR)
    {
      perror(RED "Error on send\n" RESET);
      return (ERROR);
    }
  return (n);
}
