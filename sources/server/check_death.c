/*
** check_death.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
**
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
**
** Started on  Sat Jun 27 15:59:28 2015 Audibert Louis
** Last update Sun Jul  5 10:25:15 2015 Serge Heitzler
*/

#include "functions.h"

int		get_alloc_to_delete(t_server *s)
{
  t_node	*tmp;
  t_client	*c;
  int		i;

  i = 0;
  tmp = s->clients->start;
  while (tmp != NULL)
    {
      c = tmp->data;
      if (c->type == IA && c->state == ADULT && c->inventory->food == 0)
	i++;
      tmp = tmp->next;
    }
  return (i);
}

static void		free_delete_fds(t_server *s, int **fds)
{
  int	nb;
  int	i;

  i = 0;
  nb = get_alloc_to_delete(s);
  while (i < nb)
    {
      free(fds[i]);
      i++;
    }
  free(fds);
}

void		delete_players(t_server *s, int **fds, int len)
{
  int		i;
  t_client	*c;
  t_block	*b;
  t_team	*team;
  char		*trame;

  i = 0;
  while (i < len)
    {
      c = get_client_by_id(s->clients, fds[i][1]);
      b = s->map->objects[c->pos->y][c->pos->x];
      b->ids = remove_id(s->map->objects[c->pos->y][c->pos->x], fds[i][1]);
      b->nb_clients--;
      team = get_team_by_name(s->teams, c->team_name);
      trame = xmalloc(sizeof(char) * (7 + istm(fds[i][1])));
      bzero(trame, (7 + istm(fds[i][1])));
      sprintf(trame, "pdi #%d\n", fds[i][1]);
      send_data_to_gui(s->clients, trame);
      free(trame);
      team->slot_rest++;
      remove_at_index(s->clients, fds[i][0]);
      send_data(fds[i][1], "mort\n");
      i++;
    }
  free_delete_fds(s, fds);
}

void		check_death(t_server *s)
{
  t_node	*tmp;
  t_client	*c;
  int		i;
  int		j;
  int		**delete_fds;

  i = 0;
  j = 0;
  tmp = s->clients->start;
  delete_fds = xmalloc(get_alloc_to_delete(s) * sizeof(int) * 2);
  while (tmp != NULL)
    {
      c = tmp->data;
      if (c->type == IA && c->inventory->food <= 0)
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
