/*
** cmd_ebo.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue Jun 30 15:50:26 2015 Audibert Louis
** Last update Tue Jun 30 15:53:26 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_ebo(t_egg *egg, t_list *clients)
{
  int		size_malloc;
  char		*str;

  size_malloc = 7 + istm(egg->id);
  str = xmalloc(sizeof(char) * size_malloc);
  sprintf(str, "ebo #%d\n", egg->id);
  printf("%s", str);
  send_data_to_gui(clients, str);
  return (SUCCESS);
}
