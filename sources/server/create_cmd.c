/*
** create_cmd.c for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server/list
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Tue May 26 17:23:11 2015 Serge Heitzler
** Last update Tue May 26 17:54:14 2015 Serge Heitzler
*/

#include "server.h"

t_cmd		*create_cmd(const char *cmd)
{
  t_cmd		*cmd;
  struct timespec tp;

  clock_gettime(CLOCK_REALTIME, &tp);
  /* "tp.tv_usec" = nanoseconds divide by 1000 to get microseconds*/

  printf( "Current local time and date: %s", asctime(time_info));
  return (cmd);
}
