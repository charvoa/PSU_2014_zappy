/*
** cmd_drop_object.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:33 2015 Serge Heitzler
** Last update Sun Jul  5 19:27:23 2015 Audibert Louis
*/

#include "functions.h"

t_objects	g_rocks[6] =
  {
    {"linemate", &inventory_linemate},
    {"deraumere", &inventory_deraumere},
    {"sibur", &inventory_sibur},
    {"mendiane", &inventory_mendiane},
    {"phiras", &inventory_phiras},
    {"thystame", &inventory_thystame},
  };

int		launch_func_inventory(t_client *c, int rock,
				      e_flag_rock flag)
{
  int		i;

  i = 0;
  while (i < 6)
    {
      if (i == rock)
	{
	  if (g_rocks[i].ptr_func(c->inventory, flag) == SUCCESS)
	    return (SUCCESS);
	  else
	    return (ERROR);
	}
      i++;
    }
  return (ERROR);
}

int		drop_rock(t_server *s, t_client *c, char *item)
{
  int		rock_type;

  if ((rock_type = check_rock(item)) == ERROR)
    return (ERROR);
  if (launch_func_inventory(c, rock_type, REMOVE) == ERROR)
    return (ERROR);
  if (launch_func_block(s->map->objects[c->pos->y][c->pos->x],
			rock_type, ADD) == ERROR)
    return (ERROR);
  cmd_pdr(c, s->clients, rock_type + 1);
  cmd_pin(s, c, "protocole", GUI);
  cmd_bct(s, c, "protocole", GUI);
  return (SUCCESS);
}

int		drop_food(t_server *s, t_client *c)
{
  if (c->inventory->food <= 0)
    return (ERROR);
  c->inventory->food--;
  s->map->objects[c->pos->y][c->pos->x]->food++;
  cmd_pdr(c, s->clients, 0);
  cmd_pin(s, c, "protocole", GUI);
  cmd_bct(s, c, "protocole", GUI);
  return (SUCCESS);
}

int		do_drop_object(t_server *s, t_client *c, char *item)
{
  if (strcmp(item, "nourriture") == 0)
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
  return (SUCCESS);
}

int		cmd_drop_object(t_server *s, t_client *c,
				char *cmd, e_client_type type)
{
  (void)type;
  char		*item;

  if (c->state == CHILD)
    return (ERROR);
  item = xmalloc((strlen(cmd) - 4) * sizeof(char));
  bzero(item, strlen(cmd) - 4);
  sscanf(cmd, "pose %s", item);
  if (do_drop_object(s, c, item) == ERROR)
    return (ERROR);
  send_data(c->fd, "ok\n");
  free(item);
  return (SUCCESS);
}
