/*
** options.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 11:34:34 2015 Audibert Louis
** Last update Mon Jun 22 15:02:54 2015 Audibert Louis
*/

#include <ctype.h>
#include "server.h"

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
  int	i;

  i = 0;
  s->o->optind--;
  s->teams->names = xmalloc((count_teams(s) + 1) * sizeof(char *));
  while (s->o->optind < s->o->argc && *(s->o->argv[s->o->optind]) != '-')
    {
      s->teams->names[i] = xmalloc((strlen(s->o->argv[s->o->optind]) + 1));
      bzero(s->teams->names[i], strlen(s->o->argv[s->o->optind]) + 1);
      s->teams->names[i] = strdup(s->o->argv[s->o->optind]);
      /* printf("s->teams->names[%d] = %s\n", i, s->teams->names[i]); */
      s->o->optind++;
      i++;
    }
  s->teams->names[i] = NULL;
  /* printf("s->teams->names[%d] = %s\n", i, s->teams->names[i]); */
  return (0);
}

int	opt_nb_client(t_server *s)
{
  if (is_number(s->o->optarg) != -1)
    s->teams->nb_max_clients_by_team = atoi(s->o->optarg);
  else
    return (-1);
  return (0);
}

int	opt_time_action(t_server *s)
{
  if (is_number(s->o->optarg) != -1)
    s->time_action = atoi(s->o->optarg);
  else
    return (-1);
  return (0);
}
