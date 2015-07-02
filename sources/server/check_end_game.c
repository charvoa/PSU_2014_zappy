/*
** check_end_game.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Wed Jul  1 11:14:16 2015 Audibert Louis
** Last update Thu Jul  2 15:16:54 2015 Audibert Louis
*/

#include "functions.h"

char		**get_tab_of_IA(t_list *clients)
{
  t_node	*tmp;
  char		**tab;
  t_client	*c;
  int		i;

  tmp = clients->start;
  tab = xmalloc((clients->length + 1) * sizeof(char));
  i = 0;
  while (tmp)
    {
      c = tmp->data;
      if (c->level == 8)
	{
	  tab[i] = xmalloc((strlen(c->team_name) + 1) * sizeof(char));
	  bzero(tab[i], strlen(c->team_name) + 1);
	  strcpy(tab[i], c->team_name);
	  printf("tab[i] = %s\n", tab[i]);
	  i++;
	}
      tmp = tmp->next;
    }
  tab[i] = NULL;
  return (tab);
}

int		recursv_team(char **tab, int j)
{
  int	i;
  int	nb_ia_lvl_max;

  i = 0;
  nb_ia_lvl_max = 0;
  if (j <= i)
    {
      while (tab[i])
	{
	  if (strcmp(tab[j], tab[i]) == 0)
	    nb_ia_lvl_max++;
	  i++;
	}
      if (nb_ia_lvl_max >= 6)
	return (SUCCESS);
      else
	recursv_team(tab, j++);
    }
  return (ERROR);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void		check_end_game(t_server *s)
{
  char		**tab;

  if (s->clients->length > 0)
    {
      tab = get_tab_of_IA(s->clients);
      if (recursv_team(tab, 0) == SUCCESS)
	exit(0);
      free_tab(tab);
    }
}
