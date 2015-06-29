/*
** check_death.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 15:59:28 2015 Audibert Louis
** Last update Mon Jun 29 11:29:23 2015 Audibert Louis
*/

#include "functions.h"

int		get_alloc_to_delete(t_server *s)
{
  t_node	*tmp;
  t_client	*c;
  int		i;

  c = xmalloc(sizeof(t_client));
  tmp = s->clients->start;
  i = 0;
  while (tmp != NULL)
    {
      c = tmp->data;
      if (c->inventory->food == 0)
	i++;
      tmp = tmp->next;
    }
  return (i);
}

void		delete_players(t_server *s, int **fds, int len)
{
  int		i;
  char		*trame;
  t_team	*team;

  i = 0;
  while (i < len)
    {
      team = get_team_by_name(s->teams, get_client_by_id(s->clients,
							 fds[i][1])->team_name);
      trame = xmalloc(sizeof(char) * (7 + istm(fds[i][1])));
      bzero(trame, (7 + istm(fds[i][1])));
      sprintf(trame, "pdi #%d\n", fds[i][1]);
      send_data_to_gui(s->clients, trame);
      remove_at_index(s->clients, fds[i][0]);
      team->slot_rest++;
      printf("%s\n", trame);
      close(fds[i][1]);
      i++;
      free(trame);
    }
}

void		check_death(t_server *s)
{
  t_node	*tmp;
  t_client	*c;
  int		i;
  int		j;
  int		**delete_fds;

  tmp = s->clients->start;
  delete_fds = xmalloc(get_alloc_to_delete(s) * sizeof(int));
  i = 0;
  j = 0;
  while (tmp != NULL)
    {
      c = xmalloc(sizeof(t_client));
      c = tmp->data;
      if (c->inventory->food == 0)
	{
	  delete_fds[j] = xmalloc(sizeof(int) * 2);
	  delete_fds[j][0] = i;
	  delete_fds[j][1] = c->fd;
	  j++;
	}
      i++;
      tmp = tmp->next;
    }
  delete_players(s, delete_fds, j);
}
