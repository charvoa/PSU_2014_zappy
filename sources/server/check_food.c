/*
** check_food.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Wed Jul  1 13:05:17 2015 Serge Heitzler
** Last update Sun Jul  5 01:09:08 2015 Serge Heitzler
*/

#include "functions.h"

void		d_inferior(t_server *s, long ns_delay, int billion)
{
  if (s->next.tv_nsec + ns_delay > billion)
    {
      s->next.tv_sec++;
      s->next.tv_nsec = s->next.tv_nsec + ns_delay - billion;
    }
  else
    s->next.tv_nsec += ns_delay;
}

void		d_superior(t_server *s, long ns_delay, int billion)
{
  int		mod;

  s->next.tv_sec += ns_delay / billion;
  mod = ns_delay % billion;
  if (s->next.tv_nsec + mod > billion)
    {
      s->next.tv_sec++;
      mod = s->next.tv_nsec + mod;
    }
  s->next.tv_nsec += mod;
}

void			new_ultimatum(t_server *s)
{
  float		rate;
  long		ns_delay;
  int		billion;

  billion = 1000000000;
  rate = 126 / s->time_action;
  ns_delay = rate * billion;
  if (ns_delay > billion)
    d_superior(s, ns_delay, billion);
  else
    d_inferior(s, ns_delay, billion);
}

void			decrement_food(t_server *s)
{
  t_node		*tmp;
  t_client		*c;

  tmp = s->clients->start;
  if (s->clients->length > 0)
    {
      while (tmp)
  	{
  	  c = tmp->data;
  	  if (c->type == IA)
  	    c->inventory->food--;
  	  tmp = tmp->next;
  	}
    }
}

int			check_food(t_server *s)
{
  clock_gettime(CLOCK_REALTIME, &s->now);
  if (s->next.tv_sec < s->now.tv_sec ||
      ((s->next.tv_sec == s->now.tv_sec) &&
       (s->next.tv_nsec <= s->now.tv_nsec)))
    {
      create_objects(s);
      decrement_food(s);
      new_ultimatum(s);
    }
  return (SUCCESS);
}
