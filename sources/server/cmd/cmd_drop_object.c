/*
** cmd_drop_object.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:33 2015 Serge Heitzler
** Last update Thu Jun 25 20:03:25 2015 Audibert Louis
*/

#include "server.h"

int		launch_func_rock(t_client *c, int rock, e_flag_rock flag)
{
  int		i;
  t_objects	rocks[6] =
    {
      {"limemate", &add_limemate},
      {"deraumere", &add_deraumere},
      {"sibur", &add_sibur},
      {"mendiane", &add_mendiane},
      {"phiras", &add_phiras},
      {"thystame", &add_thystame},
    };
  
  i = 0;
  while (i < 6)
    {
      if (i == rock)
	{
	  rocks[i].ptr_func(c->inventory, flag);
	  return (SUCCESS);
	}
      i++;
    }
  return (ERROR);
}

int		drop_rock(t_server *s, t_client *c, char *item)
{
  t_rock	*rock;
  int		rock_type;

  rock = xmalloc(sizeof(t_rock));
  if ((rock_type = check_rock(item)) == ERROR)
    return (ERROR);
  launch_func_rock(c, rock_type, REMOVE);
  rock->pos->x = c->pos->x;
  rock->pos->y = c->pos->y;
  rock->type = rock_type;
  push_back(s->map->objects[c->pos->y][c->pos->x], rock, ROCK);
  return (SUCCESS);
}

int		drop_food(t_server *s, t_client *c)
{
  t_food	*food;

  if (c->inventory->food <= 0)
    return (ERROR);
  food = xmalloc(sizeof(t_food));
  c->inventory->food--;
  food->pos->x = c->pos->x;
  food->pos->y = c->pos->y;
  push_back(s->map->objects[c->pos->y][c->pos->x], food, FOOD);
  return (SUCCESS);
}

int		cmd_drop_object(t_server *s, t_client *c, const char *cmd)
{
  char		*item;
  
  item = xmalloc((strlen(cmd) - 4) * sizeof(char));
  bzero(item, strlen(cmd) - 4);
  sscanf(cmd, "pose %s", item);
  if (strcmp(item, "food") == 0)
    {
      if (drop_food(s, c) == ERROR)
	{
	  send_data(c->fd, "ko\n");
	  return (ERROR);
	}
    }
  else
    {
      if (drop_rock(s, c, item) == ERROR)
	{
	  send_data(c->fd, "ko\n");
	  return (ERROR);
	}
    }
  send_data(c->fd, "ok\n");
  return (SUCCESS);
}
