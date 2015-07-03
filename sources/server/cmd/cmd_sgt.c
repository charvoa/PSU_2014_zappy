/*
** cmd_sgt.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:58 2015 Serge Heitzler
** Last update Fri Jul  3 19:46:29 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_sgt(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  (void)c;
  char		*final;

  final = xmalloc(sizeof(char) *
		  (6 + istm(s->time_action)));
  memset(final, 0, 6 + istm(s->time_action));
  sprintf(final, "sgt %.0f\n", s->time_action);
  send_data_to_gui(s->clients, final);
  free(final);
  return (SUCCESS);
}
