/*
** cmd_seg.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Thu Jul  2 15:02:03 2015 Serge Heitzler
** Last update Thu Jul  2 15:05:57 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_seg(t_list *clients, char *name)
{
  char		*str;
  int		size_malloc;

  size_malloc = 6 + strlen(name);
  str = xmalloc(sizeof(char) * size_malloc);
  sprintf(str, "seg %s\n", name);
  send_data_to_gui(clients, str);
  return (SUCCESS);
}
