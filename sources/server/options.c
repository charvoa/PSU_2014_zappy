/*
** options.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 11:34:34 2015 Audibert Louis
** Last update Wed May 13 11:42:00 2015 Audibert Louis
*/

#include <ctype.h>
#include "../../headers/server.h"

int	is_number(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
        i = i + 1;
      else
	return (-1);
    }
  return (0);
}

int	opt_port(t_server *s)
{
  if (is_number(s->optarg) != -1)
    s->port = atoi(s->optarg);
  else
    return (-1);
  return (0);
}

int	opt_teams(t_server *s)
{
  (void)s;
  return (0);
}

int	opt_nb_client(t_server *s)
{
  if (is_number(s->optarg) != -1)
    s->teams->nb_max_clients_by_team = atoi(s->optarg);
  else
    return (-1);
  return (0);
}

int	opt_time_action(t_server *s)
{
  if (is_number(s->optarg) != -1)
    s->time_action = atoi(s->optarg);
  else
    return (-1);
  return (0);
}
