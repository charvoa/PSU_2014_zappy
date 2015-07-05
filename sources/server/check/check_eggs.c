/*
** check_eggs.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Tue Jun 30 14:23:33 2015 Audibert Louis
** Last update Sun Jul  5 15:56:03 2015 Serge Heitzler
*/

#include "functions.h"

int		is_there_an_egg(t_list *eggs, char *team, int fd)
{
  t_node	*tmp;
  t_egg		*egg;

  tmp = eggs->start;
  while (tmp)
    {
      egg = tmp->data;
      if (strcmp(egg->team_name, team) == 0)
	{
	  egg->fd = fd;
	  return (SUCCESS);
	}
      tmp = tmp->next;
    }
  return (ERROR);
}

void		check_eggs(t_server *s)
{
  t_node	*tmp;
  t_egg		*egg;
  int		i;

  i = 0;
  tmp = s->eggs->start;
  while (i < s->eggs->length)
    {
      egg = tmp->data;
      if (egg->eclos.tv_sec < s->now.tv_sec ||
	  ((egg->eclos.tv_sec == s->now.tv_sec) &&
	   (egg->eclos.tv_nsec <= s->now.tv_nsec)))
	{
	  if (egg->fd != -1)
	    create_client_from_egg(s, egg, i);
	  else
	    {
	      cmd_edi(egg, s->clients);
	      remove_at_index(s->eggs, i);
	    }
	}
      i++;
      if (i < s->eggs->length)
	tmp = tmp->next;
    }
}
