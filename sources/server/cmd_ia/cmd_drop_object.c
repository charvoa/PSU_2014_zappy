/*
** cmd_drop_object.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:33 2015 Serge Heitzler
** Last update Fri Jun 19 11:29:34 2015 Serge Heitzler
*/

#include "server.h"

int		cmd_drop_object(t_server *s, t_client *c, const char *cmd)
{
  (void)cmd;
  // Les (void) du dessous sont à supprimer, celui du dessus est important et à laisser.
  (void)s;
  (void)c;
  return (SUCCESS);
}
