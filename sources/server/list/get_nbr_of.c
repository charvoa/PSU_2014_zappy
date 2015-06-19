#include "server.h"

int		get_nbr_of_rock(e_rock_type type, t_list *list)
{
  int		nbr;
  t_node	*tmp;
  t_rock	*rock;

  nbr = 0;
  tmp = list->start;
  while (tmp)
    {
      rock = tmp->data;
      if (tmp->type == ROCK && rock->type == type)
	nbr++;
      tmp = tmp->next;
    }
  free(tmp);
  free(rock);
  return (nbr);
}

int		get_nbr_of(e_node_type type, t_list *list)
{
  int		nbr;
  t_node	*tmp;

  nbr = 0;
  tmp = list->start;
  while (tmp)
    {
      if (tmp->type == type)
	nbr++;
      tmp = tmp->next;
    }
  free(tmp);
  return (nbr);
}
