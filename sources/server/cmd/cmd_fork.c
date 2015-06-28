/*
** cmd_fork.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:37 2015 Serge Heitzler
** Last update Sun Jun 28 23:16:14 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_fork(t_server *s, t_client *c,
			 const char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;

  cmd_pfk(c, s->clients);
  return (SUCCESS);
}
