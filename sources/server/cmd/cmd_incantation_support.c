/*
** cmd_incantation_support.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sat Jul  4 08:46:37 2015 Serge Heitzler
** Last update Sun Jul  5 18:06:10 2015 Serge Heitzler
*/

#include "functions.h"

char		*send_once_final_and_get_it(t_client *c)
{
  int		size_malloc;
  char		*final;

  size_malloc = 20;
  final = malloc_and_memset(size_malloc);
  sprintf(final, "elevation en cours\n");
  send_data(c->fd, final);
  return (final);
}

void		send_pie_and_plv(t_server *s, t_client *c,
			        char *cmd, e_client_type type)
{
  (void)type;
  cmd_pie(s, c, cmd, GUI);
  cmd_plv(s, c, cmd, GUI);
}

void		send_level(t_client *c)
{
  int		size_malloc;
  char		*final;

  c->level++;
  size_malloc = 18 + istm(c->level);
  final = malloc_and_memset(size_malloc);
  sprintf(final, "niveau actuel : %d\n", c->level);
  send_data(c->fd, final);
  free(final);
}

void		reset_block(t_block *b)
{
  b->linemate = 0;
  b->deraumere = 0;
  b->sibur = 0;
  b->mendiane = 0;
  b->phiras = 0;
  b->thystame = 0;
}
