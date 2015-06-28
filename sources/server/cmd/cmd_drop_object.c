/*
** cmd_drop_object.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:33 2015 Serge Heitzler
** Last update Sun Jun 28 14:43:58 2015 Audibert Louis
*/

#include "functions.h"

static void		cmd_gui_pdr(t_client *c, t_list *clients, int type)
{
  int			size_malloc;
  char			*str;

  size_malloc = (8 + istm(c->fd) + istm(type));
  str = xmalloc(sizeof(char) * size_malloc);
  bzero(str, size_malloc);
  sprintf(str, "pdr #%d %d\n", c->fd, type);
  send_data_to_gui(clients, str);
}

int		launch_func_inventory(t_client *c, int rock, e_flag_rock flag)
{
  int		i;
  t_objects	rocks[6] =
    {
      {"linemate", &inventory_linemate},
      {"deraumere", &inventory_deraumere},
      {"sibur", &inventory_sibur},
      {"mendiane", &inventory_mendiane},
      {"phiras", &inventory_phiras},
      {"thystame", &inventory_thystame},
    };

  i = 0;
  while (i < 6)
    {
      if (i == rock)
	{
	  if (rocks[i].ptr_func(c->inventory, flag) == SUCCESS)
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
  cmd_gui_pdr(c, s->clients, rock_type + 1);
  cmd_pin(s, c, "protocole", GUI);
  cmd_bct(s, c, "protocole", GUI);
  return (SUCCESS);
}

int		drop_food(t_server *s, t_client *c)
{
  printf("drop %d\n", s->map->objects[c->pos->y][c->pos->x]->food);
  if (c->inventory->food <= 0)
    return (ERROR);
  c->inventory->food--;
  s->map->objects[c->pos->y][c->pos->x]->food++;
  cmd_gui_pdr(c, s->clients, 0);
  cmd_pin(s, c, "protocole", GUI);
  cmd_bct(s, c, "protocole", GUI);
  return (SUCCESS);
}

int		cmd_drop_object(t_server *s, t_client *c,
				const char *cmd, e_client_type type)
{
  (void)type;
  char		*item;

  item = xmalloc((strlen(cmd) - 4) * sizeof(char));
  bzero(item, strlen(cmd) - 4);
  sscanf(cmd, "pose %s", item);
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
  send_data(c->fd, "ok\n");
  return (SUCCESS);
}
