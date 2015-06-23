/*
** int_size_to_malloc.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server/cmd_ia
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Fri May 22 11:25:41 2015 Serge Heitzler
** Last update Tue Jun 23 20:05:13 2015 Serge Heitzler
*/

#include "server.h"

int		istm(int nb)
{
  int		i;

  i = 1;
  while (nb > 1)
    {
      nb = nb / 10;
      i++;
    }
  return (i);
}
