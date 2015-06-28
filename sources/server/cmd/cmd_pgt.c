/*
** cmd_pgt.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jun 28 23:06:45 2015 Serge Heitzler
** Last update Sun Jun 28 23:07:17 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_pgt(t_client *c, t_list *clients, int type)
{
  int			size_malloc;
  char			*str;

  size_malloc = (8 + istm(c->fd) + istm(type));
  str = xmalloc(sizeof(char) * size_malloc);
  sprintf(str, "pdr #%d %d\n", c->fd, type);
  send_data_to_gui(clients, str);
  return (SUCCESS);
}
