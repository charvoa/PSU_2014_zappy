/*
** cmd_dead.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:16 2015 Serge Heitzler
** Last update Sat Jun 27 10:49:41 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_dead(t_server *s, t_client *c, const char *cmd)
{
  (void)cmd;
  // Les (void) du dessous sont à supprimer, celui du dessus est important et à laisser.
  (void)s;
  (void)c;
  return (SUCCESS);
}
