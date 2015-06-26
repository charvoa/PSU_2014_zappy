/*
** cmd_take_object.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:30:02 2015 Serge Heitzler
** Last update Thu Jun 25 20:03:03 2015 Audibert Louis
*/

#include "server.h"

int		check_rock(char *rock)
{
  char	**rocks;
  int	i;
  
  rocks = malloc(7 * sizeof(char*));
  rocks[0] = "limemate";
  rocks[1] = "deraumere";
  rocks[2] = "sibur";
  rocks[3] = "mendiane";
  rocks[4] = "phiras";
  rocks[5] = "thystame";
  rocks[6] = NULL;
  i = 0;
  while (rocks[i])
    {
      if (strncmp(rock, rocks[i], strlen(rock)) == 0)
	return (i);
      i++;
    }
  return (ERROR);
}

int		remove_rock(t_node *tmp, t_list *list, int rock_type, int index)
{
  t_rock	*rock;

  rock = xmalloc(sizeof(t_rock));
  rock = tmp->data;
  if ((int)rock->type == rock_type)
    {
      remove_at_index(list, index);
      return (SUCCESS);
    }
  return (ERROR);
}

int		take_rock(t_server *s, t_client *c, char *item)
{
  t_node	*tmp;
  int		nb_rocks;
  int		i;
  int		rock_type;

  if ((rock_type = check_rock(item)) == ERROR)
    return (ERROR);
  if ((nb_rocks = get_nbr_of(ROCK, s->map->objects[c->pos->y][c->pos->x])) == 0)
    return (ERROR);
  tmp =  s->map->objects[c->pos->y][c->pos->x]->start;
  i = 0;
  while (tmp)
    {
      if (tmp->type == ROCK)
	{
	  if (remove_rock(tmp, s->map->objects[c->pos->y][c->pos->x],
			  rock_type, i) == SUCCESS)
	    {
	      launch_func_rock(c, rock_type, ADD);
	      return (SUCCESS);
	    }
	}
      i++;
      tmp = tmp->next;
    }
  return (ERROR);
}

int		take_food(t_server *s, t_client *c)
{
  t_node	*tmp;
  int		nb_food;
  int		i;

  nb_food = get_nbr_of(FOOD, s->map->objects[c->pos->y][c->pos->x]);
  if (nb_food == 0)
    return (ERROR);
  tmp = s->map->objects[c->pos->y][c->pos->x]->start;
  i = 0;
  while (tmp)
    {
      if (tmp->type == FOOD)
	{
	  remove_at_index(s->map->objects[c->pos->y][c->pos->x], i);
	  c->inventory->food++;
	  return (SUCCESS);
	}
      i++;
      tmp = tmp->next;
    }
  return (ERROR);
}

int		cmd_take_object(t_server *s, t_client *c, const char *cmd)
{
  char		*item;

  item = xmalloc((strlen(cmd) - 7) * sizeof(char));
  bzero(item, strlen(cmd) - 7);
  sscanf(cmd, "prend %s", item);
  if (strcmp(item, "food") == 0)
    {
      if (take_food(s, c) == ERROR)
	{
	  send_data(c->fd, "ko\n");
	  return (ERROR);
	}
    }
  else
    {
      if (take_rock(s, c, item) == ERROR)
	{
	  send_data(c->fd, "ko\n");
	  return (ERROR);
	}
    }
  send_data(c->fd, "ok\n");
  return (SUCCESS);
}
