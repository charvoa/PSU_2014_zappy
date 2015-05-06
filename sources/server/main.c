/*
** server.c for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:25:19 2015 Nicolas Charvoz
** Last update Wed May  6 14:50:26 2015 Audibert Louis
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
  printf("The server will close ...\n");
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
      printf("Server-select() is OK...\n");
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

t_server	*fill_struct_serv(int argc, char **argv)
{
  t_server	*s;
  int		opt;

  s = xmalloc(sizeof(*s));
  while ((opt = getopt(argc, argv,"p:x:y:nc:t:")) != -1)
    {
      switch (opt) 
	{
	case 'p' : s->port = atoi(optarg);
	  break;
	case 'x' : s->Xmap = atoi(optarg);
	  break;
	case 'y' : s->Ymap = atoi(optarg); 
	  break;
	case 'n' : s->team_names = optarg; // récupérer tous les args et non pas qu'un seul...
	  break;
	case 'c' : s->nb_max_clients_by_team = atoi(optarg);
	  break;
	case 't' : s->time_action = atoi(optarg);
	  break;
	default :
	  s->port = 4242;
	  s->Xmap = 20;
	  s->Ymap = 20;
	  s->nb_max_clients_by_team = 2;
	}
    }
  return (s);
}

int		main(int argc, char **argv)
{
  t_server	*s;

  s = fill_struct_serv(argc, argv);
  init_socket(s);
  bind_socket(s, 4242);
  xlisten(s->listener, 10);
  FD_SET(s->listener, &(s->master));
  s->fdmax = s->listener;
  loop_server(s, argv);
  return (0);
}
