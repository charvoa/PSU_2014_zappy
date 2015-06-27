/*
** cmd_bct.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:20 2015 Serge Heitzler
** Last update Sat Jun 27 10:49:19 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_bct(t_server *s, t_client *c, const char *cmd)
{
  int		*x;
  int		*y;
  char		*final;
  char		*tmp;

  x = xmalloc(sizeof(int));
  y = xmalloc(sizeof(int));
  sscanf(cmd, "bct %d %d", x, y);
  tmp = show_items_at_position(s, *x, *y);
  final = xmalloc(sizeof(char) * (9 + istm(*x)
				  + istm(*y) + strlen(tmp)));
  memset(final, 0, (9 + istm(*x)
		    + istm(*y) + strlen(tmp)));
  sprintf(final, "bct %d %d {%s}\n", *x, *y, tmp);
  send_data(c->fd, final);
  return (SUCCESS);
}
