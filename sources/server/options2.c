/*
** options2.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 14:05:42 2015 Audibert Louis
** Last update Wed Jul  1 14:28:26 2015 Audibert Louis
*/

#include "functions.h"

int	opt_width_map(t_server *s)
{
  if (is_number(s->o->optarg) != -1)
    {
      if (atoi(s->o->optarg) > 7)
	s->map_set[0] = atoi(s->o->optarg);
      else
	{
	  printf("Map width and height have to be at least 7 * 7\n");
	  exit(-1);
	}
    }
  else
    return (-1);
  return (0);
}

int	opt_height_map(t_server *s)
{
  if (is_number(s->o->optarg) != -1)
    {
      if (atoi(s->o->optarg) > 7)
	s->map_set[1] = atoi(s->o->optarg);
      else
	{
	  printf("Map width and height have to be at least 7 * 7\n");
	  exit(-1);
	}
    }
  else
    return (-1);
  return (0);
}

int	opt_verbose(t_server *s)
{
  (void)s;
  my_printf("OPT VERBOSE\n");
  g_verbose = 1;
  return (0);
}
