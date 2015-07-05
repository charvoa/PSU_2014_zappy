/*
** cmd_pbc.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jun 28 23:30:52 2015 Serge Heitzler
** Last update Sun Jul  5 18:20:28 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_pbc(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  (void)type;
  int		size_final;
  char		*final;
  char		*tmp;

  tmp = xmalloc(sizeof(char) * (strlen(cmd) - 9));
  bzero(tmp, (strlen(cmd) - 9));
  sscanf(cmd, "broadcast %4050[^\n]", tmp);
  size_final = 8 + istm(c->fd) + strlen(tmp);
  final = xmalloc(sizeof(char) * size_final);
  bzero(final, size_final);
  sprintf(final, "pbc #%d %s\n", c->fd, tmp);
  send_data_to_gui(s->clients, final);
  free(tmp);
  free(final);
  return (SUCCESS);
}
