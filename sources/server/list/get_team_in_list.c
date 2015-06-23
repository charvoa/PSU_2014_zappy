/*
** get_team_in_list.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue Jun 23 18:36:37 2015 Audibert Louis
** Last update Tue Jun 23 20:27:19 2015 Audibert Louis
*/

#include "server.h"

void		set_slot_max_by_team(t_list *list, int value)
{
  t_node	*tmp;
  t_team	*team;

  tmp = list->start;
  team = xmalloc(sizeof(t_team));
  team = tmp->data;
  while (tmp)
    {
      team = tmp->data;
      team->slot_max = value;
      tmp = tmp->next;
    }
}

t_team		*get_team_by_name(t_list *list, char *name)
{
  t_node	*tmp;
  t_team	*team;

  tmp = list->start;
  team = xmalloc(sizeof(t_team));
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
