/*
** cmd_pie.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jun 28 23:28:44 2015 Serge Heitzler
** Last update Thu Jul  2 14:33:41 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_pie(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  (void)s;
  (void)cmd;
  (void)type;
  int		size_malloc;
  char		*str;

  size_malloc = 8 + istm(c->pos->x) + istm(c->pos->y) + 1;
  str = xmalloc(sizeof(char) * size_malloc);
  sprintf(str, "pie %d %d %d\n", c->pos->x, c->pos->y, 1);
  send_data_to_gui(s->clients, str);
  return (SUCCESS);
}
