/*
** get_team_in_list.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue Jun 23 18:36:37 2015 Audibert Louis
** Last update Sun Jul  5 17:51:31 2015 Serge Heitzler
*/

#include "functions.h"

char		*get_team_name_at_index(t_list *list, int index)
{
  t_node	*tmp;
  t_team	*team;
  int		i;

  i = 0;
  tmp = list->start;
  team = xmalloc(sizeof(t_team));
  team = tmp->data;
  while (tmp)
    {
      team = tmp->data;
      if (i == index)
	return (team->name);
      tmp = tmp->next;
      i++;
    }
  return (NULL);
}

void		set_slot_for_team(t_list *list, char *type, int value)
{
  t_node	*tmp;
  t_team	*team;

  tmp = list->start;
  team = xmalloc(sizeof(t_team));
  team = tmp->data;
  while (tmp)
    {
      team = tmp->data;
      if (strcmp(type, "slot_rest") == 0)
	team->slot_rest = value;
      if (strcmp(type, "slot_max") == 0)
	team->slot_max = value;
      tmp = tmp->next;
    }
}

t_team		*get_team_by_name(t_list *list, char *name)
{
  t_node	*tmp;
  t_team	*team;

  tmp = list->start;
  team = tmp->data;
  while (tmp)
    {
      team = tmp->data;
      if (strcmp(name, team->name) == 0)
	return (team);
      tmp = tmp->next;
    }
  return (NULL);
}
