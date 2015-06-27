/*
** count_teams.c for zappy in /home/heitzls/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <heitzls@epitech.net>
** 
** Started on  Fri May 22 13:32:55 2015 Serge Heitzler
** Last update Sat Jun 27 10:42:08 2015 Audibert Louis
*/

#include "functions.h"

int	count_teams(t_server *s)
{
  int	save;
  int	i;

  i = 0;
  save = 0;
  save = s->o->optind;
  while (s->o->optind < s->o->argc && *(s->o->argv[s->o->optind]) != '-')
    {
      i++;
      s->o->optind++;
    }
  s->o->optind = save;
  return (i);
}
