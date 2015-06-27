/*
** size_of_tab.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 26 16:44:56 2015 Audibert Louis
** Last update Sat Jun 27 10:47:47 2015 Audibert Louis
*/

#include "functions.h"

int		size_of_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
