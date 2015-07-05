/*
** options.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 11:34:34 2015 Audibert Louis
** Last update Sun Jul  5 19:42:43 2015 Audibert Louis
*/

#include <ctype.h>
#include "functions.h"

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
  if (is_number(s->o->optarg) != -1)
    s->port = atoi(s->o->optarg);
  else
    return (-1);
  return (0);
}

int	opt_teams(t_server *s)
{
  s->o->optind--;
  while (s->o->optind < s->o->argc && *(s->o->argv[s->o->optind]) != '-')
    {
      push_back(s->teams,
		create_team(s, s->o->argv[s->o->optind], 10), TEAM);
      my_printf("s->o->argv[s->o->optind] = %s\n",
		s->o->argv[s->o->optind]);
      s->o->optind++;
    }
  return (0);
}

int	opt_nb_client(t_server *s)
{
  if (is_number(s->o->optarg) != -1)
    set_slot_for_team(s->teams, "slot_max", atoi(s->o->optarg));
  else
    {
      printf("-c set to 10 (default value)\n");
      return (-1);
    }
  return (0);
}

int	opt_time_action(t_server *s)
{
  if (is_number(s->o->optarg) != -1)
    {
      if (atoi(s->o->optarg) <= 0)
	return (-1);
      else if (atoi(s->o->optarg) > 10000)
	return (-1);
      s->time_action = atoi(s->o->optarg);
    }
  else
    {
      printf("-t set to 100 (default value)\n");
      return (-1);
    }
  return (0);
}
