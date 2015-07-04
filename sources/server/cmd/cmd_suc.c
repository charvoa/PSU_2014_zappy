/*
** cmd_suc.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jul  3 15:03:05 2015 Audibert Louis
** Last update Fri Jul  3 19:42:19 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_suc(t_client *client)
{
  char		*trame;

  trame = xmalloc(5 * sizeof(char));
  bzero(trame, 5);
  sprintf(trame, "suc\n");
  send_data(client->fd, trame);
  free(trame);
  return (SUCCESS);
}
