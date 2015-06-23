/*
** server.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
**
** Started on  Sat May 16 18:32:59 2015 Serge Heitzler
** Last update Tue Jun 23 21:37:41 2015 Serge Heitzler
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

char	**get_tab(int argc, char **argv)
{
  char	**tab;
  int	i;

  tab = xmalloc((argc + 1) * sizeof(char*));
  i = 0;
  while (argv[i])
    {
      tab[i] = xmalloc((strlen(argv[i]) + 1) * sizeof(char));
      bzero(tab[i], (strlen(argv[i]) + 1));
      strcpy(tab[i], argv[i]);
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

void	init_opt_server(t_server *s)
{
  s->o = xmalloc(sizeof(*s->o));
  s->port = 4242;
  s->time_action = 1;
}

t_server	*fill_struct_serv(int argc, char **argv)
{
  t_server	*s;
  int		opt;
  int		(*options[6])(t_server *s);

  s = xmalloc(sizeof(t_server));
  s->graph = xmalloc(sizeof(t_server_graph));
  s->graph->connected = FALSE;
  init_map(s, 20, 20);
  init_opt(options);
  s->teams = create_list();
  init_opt_server(s);
  s->clients = create_list();
  s->o->argc = argc;
  s->o->argv = get_tab(argc, argv);
  while ((opt = getopt(argc, argv,"p:x:y:n:c:t:v")) != -1)
    {
      s->o->opt = opt;
      s->o->optarg = optarg;
      s->o->optind = optind;
      exec_option(s, options);
    }
  set_slot_for_team(s->teams, "slot_rest", 10);
  set_slot_for_team(s->teams, "slot_team", 10);
  return (s);
}
