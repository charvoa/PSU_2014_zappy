/*
** exec_cmd.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
**
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
**
** Started on  Thu May  7 15:24:45 2015 Audibert Louis
** Last update Wed May 27 00:03:08 2015 Serge Heitzler
*/

#include "server.h"

void	init_cmd(int	(*cmd[13])(t_server *s))
{
  cmd[0] = &cmd_team;
}

char	**get_cmd_tab()
{
  char	**tab;

  tab = xmalloc(13 * sizeof(char*));
  tab[0] = "TEAM";
  tab[1] = NULL;
  return (tab);
}

int	check_cmd(char *cmd)
{
  char	**tab;
  int	i;

  i = 0;
  tab = get_cmd_tab();
  while (i < 1)
    {
      if (strcmp(tab[i], cmd) == 0)
	return (i);
      i++;
    }
  free(tab);
  return (-1);
}

void	exec_cmd(t_server *s)
{
  int	(*cmd[13])(t_server *s);
  int	i;

  i = 0;
  parser(s, s->buf);
  init_cmd(cmd);
  while (i < 1)
    {
      printf("tab[%d] = %s\n", i, s->tab[i]);
      if (check_cmd(s->tab[0]) == -1)
	fprintf(stderr, "Bad cmd: %s\n", s->tab[0]);
      else
	cmd[check_cmd(s->tab[i])](s);
      i++;
    }
}
