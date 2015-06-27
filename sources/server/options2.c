/*
** options2.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 14:05:42 2015 Audibert Louis
** Last update Sat Jun 27 10:48:11 2015 Audibert Louis
*/

#include "functions.h"

int	opt_width_map(t_server *s)
{
  if (is_number(s->o->optarg) != -1)
    {
      printf("before atoi X\n");
      printf("s->map->width = %d\n", s->map->size->width);
      s->map->size->width = atoi(s->o->optarg);
      printf("after atoi X\n");
    }
  else
    return (-1);
  return (0);
}

int	opt_height_map(t_server *s)
{
  if (is_number(s->o->optarg) != -1)
    {
      printf("before atoi Y\n");
      s->map->size->height = atoi(s->o->optarg);
      printf("after atoi Y\n");
    }
  else
    return (-1);
  return (0);
}

int	opt_verbose(t_server *s)
{
  (void)s;
  g_verbose = 1;
  return (0);
}
