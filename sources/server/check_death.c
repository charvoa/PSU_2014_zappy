/*
** check_death.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 15:59:28 2015 Audibert Louis
** Last update Sun Jun 28 10:47:53 2015 Audibert Louis
*/

#include "functions.h"

int		get_alloc_to_delete(t_server *s)
{
  t_node	*tmp;
  t_client	*c;
  int		i;

  tmp = s->clients->start;
  i = 0;
  while (tmp != NULL)
    {
      c = xmalloc(sizeof(t_client));
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

  i = 0;
  //VERIFIER SI MALLOC + FREE A CHAQUE TOUR DE BOUCLE FONCTIONNE
  trame = xmalloc((strlen("pdi #\n") + 50) * sizeof(int));
  while (i < len)
    {
      bzero(trame, strlen("pdi #\n") + 50);
      printf("fds[%d][1] = %d\n", i, fds[i][1]);
      sprintf(trame, "pdi #%d\n", fds[i][1]);
      send_data_to_gui(s->clients, trame);
      remove_at_index(s->clients, fds[i][0]);
      i++;
    }
}

void		check_death(t_server *s)
{
  t_node	*tmp;
  t_client	*c;
  int		i;
  int		j;
  int		**delete_fds;

  delete_fds = xmalloc(get_alloc_to_delete(s) * 2 * sizeof(int));
  tmp = s->clients->start;
  i = 0;
  j = 0;
  while (tmp != NULL)
    {
      c = xmalloc(sizeof(t_client));
      c = tmp->data;
      if (c->inventory->food == 0)
	{
	  delete_fds[j][0] = i;
	  delete_fds[j][1] = c->fd;
	  j++;
	}
      i++;
      tmp = tmp->next;
    }
  delete_players(s, delete_fds, j);
}
