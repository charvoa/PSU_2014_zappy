/*
** commands.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 16:30:08 2015 Audibert Louis
** Last update Sat Jun 20 10:15:59 2015 Serge Heitzler
*/

#include "server.h"

int	is_a_team(t_server *s)
{
  int	i;

  i = 0;
  while (s->teams->names[i] != NULL)
    {
      if (strcmp(s->teams->names[i], s->tab[1]) == 0)
	return (0);
      i++;
    }
  return (-1);
}

int	cmd_team(t_server *s)
{
  char	trame[21];

  bzero(trame, 21);
  if (is_a_team(s) == 0)
    {
      if (s->teams->slot_rest >= 1)
	{
	  sprintf(trame, "%d", s->teams->slot_rest);
	  send_data(s->newfd, trame);
	  s->teams->slot_rest --;
	}
      else
	send_data(s->newfd, "NO_SLOT_REST\r\n");
    }
  bzero(trame, 21);
  sprintf(trame, "%d - %d", s->map->size->width, s->map->size->height);
  send_data(s->newfd, trame);
  return (0);
}
