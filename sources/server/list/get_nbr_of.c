/*
** get_nbr_of.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:28:32 2015 Serge Heitzler
** Last update Fri Jun 19 11:28:33 2015 Serge Heitzler
*/

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
