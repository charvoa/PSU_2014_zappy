/*
** cmd_smg.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jul  3 15:06:33 2015 Audibert Louis
** Last update Fri Jul  3 15:09:54 2015 Audibert Louis
*/

#include "functions.h"

int		cmd_smg(t_server *s, t_client *c, char *msg, e_client_type type)
{
  char		*trame;

  trame = xmalloc((strlen(msg) + 5) * sizeof(char));
  bzero(trame, strlen(msg) + 5);
  sprintf(trame, "smg %s\n", msg);
  if (type == GUI)
    send_data_to_gui(s->clients, trame);
  else
    send_data(c->fd, trame);
  return (SUCCESS);
}
