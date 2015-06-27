/*
** int_size_to_malloc.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server/cmd_ia
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Fri May 22 11:25:41 2015 Serge Heitzler
** Last update Sat Jun 27 18:45:27 2015 Serge Heitzler
*/

#include "functions.h"

int		istm(int nb)
{
  int		i;

  i = 1;
  while (nb >= 10)
    {
      nb = nb / 10;
      i++;
    }
  printf("[istm] %d\n", i);
  return (i);
}
