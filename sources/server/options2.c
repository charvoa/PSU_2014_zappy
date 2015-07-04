/*
** options2.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 14:05:42 2015 Audibert Louis
** Last update Sat Jul  4 17:38:39 2015 Audibert Louis
*/

#include "functions.h"

int	opt_width_map(t_server *s)
{
  if (is_number(s->o->optarg) != -1)
    {
      if (atoi(s->o->optarg) >= 7)
	s->map_set[0] = atoi(s->o->optarg);
      else
	{
	  printf("Map width and height have to be at least 7 * 7\n");
	  exit(-1);
	}
    }
  else
    {
      printf("X map have to be numeric\nDefault X is 7\n");
      return (-1);
    }
  return (0);
}

int	opt_height_map(t_server *s)
{
  if (is_number(s->o->optarg) != -1)
    {
      if (atoi(s->o->optarg) >= 7)
	s->map_set[1] = atoi(s->o->optarg);
      else
	{
	  printf("Map width and height have to be at least 7 * 7\n");
	  exit(-1);
	}
    }
  else
    {
      printf("Y map have to be numeric\nDefault X is 7");
      return (-1);
    }
  return (0);
}

int	opt_verbose(t_server *s)
{
  (void)s;
  g_verbose = 1;
  return (0);
}
