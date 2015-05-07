/*
** options2.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 14:05:42 2015 Audibert Louis
** Last update Thu May  7 15:11:55 2015 Audibert Louis
*/

#include "../../headers/server.h"

int	opt_x_map(t_server *s)
{
  if (is_number(s->optarg) != -1)
    s->map->width = atoi(s->optarg);
  else
    return (-1);
  return (0);
}

int	opt_y_map(t_server *s)
{
  if (is_number(s->optarg) != -1)
    s->map->height = atoi(s->optarg);
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
