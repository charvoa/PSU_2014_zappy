/*
** fill_struct_serv.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu Jul  2 11:07:21 2015 Audibert Louis
** Last update Sun Jul  5 17:38:07 2015 Serge Heitzler
*/

#include "functions.h"

char		**get_tab(int argc, char **argv)
{
  char		**tab;
  int		i;

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

void		init_everything(t_server *s, int argc, char **argv)
{
  s->teams = create_list();
  s->o = xmalloc(sizeof(*s->o));
  s->port = 4242;
  s->time_action = 100;
  s->map_set[0] = 0;
  s->map_set[1] = 0;
  s->clients = create_list();
  s->eggs = create_list();
  s->o->argc = argc;
  s->o->argv = get_tab(argc, argv);
  s->o->team_active = 0;
}

t_server	*fill_struct_serv(int argc, char **argv)
{
  t_server	*s;
  int		opt;
  int		(*options[7])(t_server *s);

  s = xmalloc(sizeof(t_server));
  init_opt(options);
  init_everything(s, argc, argv);
  while ((opt = getopt(argc, argv,"p:x:y:n:c:t:v")) != -1)
    {
      if (opt == 'n')
      	s->o->team_active = 1;
      s->o->opt = opt;
      s->o->optarg = optarg;
      s->o->optind = optind;
      exec_option(s, options);
    }
  if (s->o->team_active == 0)
    {
      printf("Usage: ./zappy_server -n 'team' 'team' ...\n");
      exit(-1);
    }
  launch_init_map(s);
  set_slot_for_team(s->teams, "slot_rest", 10);
  set_slot_for_team(s->teams, "slot_max", 10);
  return (s);
}
