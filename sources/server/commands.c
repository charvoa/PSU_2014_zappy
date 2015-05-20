/*
** commands.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 16:30:08 2015 Audibert Louis
** Last update Wed May 20 16:26:24 2015 Audibert Louis
*/

#include "server.h"

int	is_a_team(t_server *s)
{
  int	i;

  i = 0;
  while (s->teams->team_names[i] != NULL)
    {
      if (s->teams->team_names[i] == s->tab[1])
	return (0);
      i++;
    }
  return (-1);
}

int	cmd_team(t_server *s)
{
  char	trame[3];

  bzero(trame, 3);
  if (is_a_team(s) == 0)
    {
      if (s->teams->slot_rest >= 1)
	{
	  sprintf(trame, "%d", s->teams->slot_rest);
	  write_to_client(s, trame);
	  s->teams->slot_rest --;
	}
      else
	write_to_client(s, "NO_SLOT_REST");
    }
  bzero(trame, 3);
  sprintf(trame, "%d\r\n", s->map->size->width);
  write_to_client(s, trame);
  bzero(trame, 3);
  sprintf(trame, "%d\r\n", s->map->size->height);
  write_to_client(s, trame);
  return (0);
}
