/*
** set_options.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 11:16:33 2015 Audibert Louis
** Last update Thu May  7 11:39:33 2015 Audibert Louis
*/

#include "server.h"

void	init_opt(int (*options[5])(t_server *s))
{
  options[0] = &opt_port;
  options[1] = &opt_x_map;
  options[2] = &opt_y_map;
  options[3] = &opt_teams;
  options[4] = &opt_nb_client;
  options[5] = &opt_time_action;
}


int	check_cmd(int opt)
{
  char	*options;
  int	i;

  i = 0;
  options = strcmp("pxynct");
  while (i < 6)
    {
      if (opt == options[i])
	return (i);
      i++;
    }
  return (-1);
}

void	exec_option(t_server *s, int opt, char *optarg)
{
  int	(*options[6])(t_server *s);
  int	i;

  i = 0;
  init_opt(options);
  while (i != 6)
    {
      if (check_cmd(opt) == -1)
	fprintf(stderr, "Bad opt: %c\n", (char)opt);
      else
	options[check_cmd(opt)](s);
      i++;
    }
}
