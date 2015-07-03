/*
** cmd_pfk.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jun 28 23:15:33 2015 Serge Heitzler
** Last update Fri Jul  3 18:16:55 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_pfk(t_client *c, t_list *clients)
{
  int		size_malloc;
  char		*str;

  size_malloc = 7 + istm(c->fd);
  str = xmalloc(sizeof(char) * size_malloc);
  sprintf(str, "pfk #%d\n", c->fd);
  send_data_to_gui(clients, str);
  return (SUCCESS);
}
