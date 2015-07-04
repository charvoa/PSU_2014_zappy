/*
** cmd_pdr.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jun 28 23:02:25 2015 Serge Heitzler
** Last update Fri Jul  3 19:30:32 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_pdr(t_client *c, t_list *clients, int type)
{
  int			size_malloc;
  char			*str;

  size_malloc = (8 + istm(c->fd) + istm(type));
  str = xmalloc(sizeof(char) * size_malloc);
  bzero(str, size_malloc);
  sprintf(str, "pdr #%d %d\n", c->fd, type);
  send_data_to_gui(clients, str);
  free(str);
  return (SUCCESS);
}
