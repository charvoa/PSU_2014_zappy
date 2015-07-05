/*
** server.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
**
** Started on  Sat May 16 18:32:59 2015 Serge Heitzler
** Last update Sun Jul  5 19:43:42 2015 Audibert Louis
*/

#include "functions.h"

int	g_listener;
int	g_fdmax;
int	g_verbose = 0;

void	handler_ctrl_c(int sig)
{
  int	i;

  i = 0;
  sig = sig;
  my_printf("The server will close ...\n");
  while (i < g_fdmax)
    {
      close(i);
      i++;
    }
  close(g_listener);
  exit(0);
}

int		check_fds(t_server *s, char **argv)
{
  int		i;

  i = 0;
  while (i <= s->fdmax)
    {
      if (FD_ISSET(i, &(s->read_fds)))
	{
	  if (i == s->listener)
	    {
	      if (accept_server(s, argv) == ERROR)
		{
		  printf("accept server sent error\n");
		  return (ERROR);
		}
	    }
	  else
	    read_write_server(s, i, argv);
	}
      i++;
    }
  return (SUCCESS);
}

void		loop_server(t_server *s, char **argv)
{
  struct timeval tv;

  tv.tv_sec = 0;
  clock_gettime(CLOCK_REALTIME, &s->next);
  while (42)
    {
      s->read_fds = s->master;
      check_food(s);
      check_death(s);
      check_end_game(s);
      check_eggs(s);
      tv.tv_usec = 1000000 / s->time_action;
      signal(SIGINT, handler_ctrl_c);
      if (select(s->fdmax + 1, &(s->read_fds), NULL, NULL, &tv) == -1)
	{
	  perror("Server-select() error !");
	  exit(1);
	}
      if (check_fds(s, argv) == SUCCESS)
	check_exec(s);
    }
}
