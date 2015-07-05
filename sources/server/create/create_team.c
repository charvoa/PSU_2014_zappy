/*
** create_team.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue Jun 23 17:57:11 2015 Audibert Louis
** Last update Wed Jul  1 14:28:14 2015 Audibert Louis
*/

#include "functions.h"

t_team		*create_team(t_server *s, char *name, int nb_max)
{
  (void)s;
  t_team	*team;

  team = xmalloc(sizeof(t_team));
  team->name = strdup(name);
  team->slot_rest = nb_max;
  team->slot_max = nb_max;
  my_printf("Team %s created !\n", name);
  return (team);
}
