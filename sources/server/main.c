/*
** server.c for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:25:19 2015 Nicolas Charvoz
** Last update Wed May  6 19:16:12 2015 Serge Heitzler
*/

#include "server.h"

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

void		loop_server(t_server *s, char **argv)
{
  int		i;

  while (42)
    {
      i = 0;
      s->read_fds = s->master;
      signal(SIGINT, handler_ctrl_c);
      if (select(s->fdmax + 1, &(s->read_fds), NULL, NULL, NULL) == -1)
	{
	  perror("Server-select() error !");
	  exit(1);
	}
      my_printf("Server-select() is OK...\n");
      while (i <= s->fdmax)
	{
	  if (FD_ISSET(i, &(s->read_fds)))
	    {
	      if (i == s->listener)
		accept_server(s, argv);
	      else
		read_write_server(s, i, argv);
	    }
	  i++;
	}
    }
}

int		main(int argc, char **argv)
{
  t_server	*s;
  int		c;
  int		port;
  char		path[4096];

  getcwd(path, 4096);
  if (argc >= 2)
    port = atoi(argv[1]);
  else
    port = 4242;
  while ((c = getopt(argc, argv, "v")) != -1)
    {
      if (c == 'v')
	g_verbose = 1;
    }
  s = xmalloc(sizeof(*s));
  init_socket(s);
  bind_socket(s, port);
  xlisten(s->listener, 10);
  FD_SET(s->listener, &(s->master));
  s->fdmax = s->listener;
  s->home = path;
  loop_server(s, argv);
  return (0);
}
