/*
** cmd_eht.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue Jun 30 15:42:54 2015 Audibert Louis
** Last update Tue Jun 30 15:53:56 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_eht(t_egg *egg, t_list *clients)
{
  int		size_malloc;
  char		*str;

  size_malloc = 7 + istm(egg->id);
  str = xmalloc(sizeof(char) * size_malloc);
  sprintf(str, "eht #%d\n", egg->id);
  printf("%s", str);
  send_data_to_gui(clients, str);
  return (SUCCESS);
}
