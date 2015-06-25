/*
** cmd_drop_object.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:33 2015 Serge Heitzler
** Last update Thu Jun 25 14:52:12 2015 Audibert Louis
*/

#include "server.h"

int		drop_rock(t_server *s, t_client *c, char *item)
{
  t_node	*tmp;
  t_rock	*rock;
  int		rock_type;
  int		nb_rocks;
  int		i;

  rock = xmalloc(sizeof(t_rock));
  if ((rock_type = check_rock(item)) == ERROR)
    return (ERROR);
  if ((nb_rocks = get_nbr_of(ROCK, c->inventory)) == 0)
    return (ERROR);
  tmp = c->inventory->start;
  i = 0;
  while (tmp)
    {
      if (tmp->type == ROCK)
	{
	  if (remove_rock(tmp, c->inventory, rock_type, i) == SUCCESS)
	    {
	      rock = tmp->data;
	      push_back(s->map->objects[c->pos->y][c->pos->x], rock, ROCK);
	      return (SUCCESS);
	    }
	}
      i++;
      tmp = tmp->next;
    }
  return (ERROR);
}

int		drop_food(t_server *s, t_client *c)
{
  t_node	*tmp;
  t_food	*food;
  int		nb_food;
  int		i;

  if ((nb_food = get_nbr_of(FOOD, c->inventory)) == 0)
    return (ERROR);
  food = xmalloc(sizeof(t_food));
  tmp = c->inventory->start;
  i = 0;
  while (tmp)
    {
      if (tmp->type == FOOD)
	{
	  food = tmp->data;
	  remove_at_index(c->inventory, i);
	  push_back(s->map->objects[c->pos->y][c->pos->x], food, FOOD);
	}
      i++;
      tmp = tmp->next;
    }
  return (ERROR);
}

int		cmd_drop_object(t_server *s, t_client *c, const char *cmd)
{
  // Les (void) du dessous sont à supprimer, celui du dessus est important et à laisser.
  char		*item;
  
  item = xmalloc((strlen(cmd) - 4) * sizeof(char));
  bzero(item, strlen(cmd) - 4);
  sscanf(cmd, "pose %s", item);
  if (strcmp(item, "food") == 0)
    {
      if (drop_food(s, c) == ERROR)
	{
	  send_data(c->fd, "ko\r\n");
	  return (ERROR);
	}
    }
  else
    {
      if (drop_rock(s, c, item) == ERROR)
	{
	  send_data(c->fd, "ko\r\n");
	  return (ERROR);
	}
    }
  send_data(c->fd, "ok\r\n");
  return (SUCCESS);
}
