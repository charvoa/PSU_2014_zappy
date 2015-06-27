/*
** cmd_incantation.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:07 2015 Serge Heitzler
** Last update Sat Jun 27 16:58:54 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_incantation(t_server *s, t_client *c,
				const char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  // Les (void) du dessous sont à supprimer, celui du dessus est important et à laisser.
  (void)s;
  (void)c;
  return (SUCCESS);
}
