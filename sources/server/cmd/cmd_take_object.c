/*
** cmd_take_object.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:30:02 2015 Serge Heitzler
** Last update Sat Jun 27 17:36:54 2015 Audibert Louis
*/

#include "functions.h"

static void		cmd_gui_pgt(t_client *c, t_list *clients, int type)
{
  char	*str;

  str = xmalloc(strlen("pdr # \n") + 50);
  sprintf(str, "pdr #%d %d\n", c->fd, type);
  send_data_to_gui(clients, str);
}

int		check_rock(char *rock)
{
  char	**rocks;
  int	i;

  rocks = malloc(7 * sizeof(char*));
  rocks[0] = "linemate";
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

int		launch_func_block(t_block *block, int rock_type, e_flag_rock flag)
{
  int		i;
  t_objects	rocks[6] =
    {
      {"linemate", &block_linemate},
      {"deraumere", &block_deraumere},
      {"sibur", &block_sibur},
      {"mendiane", &block_mendiane},
      {"phiras", &block_phiras},
      {"thystame", &block_thystame},
    };

  i = 0;
  while (i < 6)
    {
      if (i == rock_type)
	{
	  rocks[i].ptr_func(block, flag);
	  return (SUCCESS);
	}
      i++;
    }
  return (ERROR);
}

int		take_rock(t_server *s, t_client *c, char *item)
{
  int		rock_type;

  if ((rock_type = check_rock(item)) == ERROR)
    return (ERROR);
  launch_func_inventory(c, rock_type, ADD);
  launch_func_block(s->map->objects[c->pos->y][c->pos->x], rock_type, REMOVE);
  cmd_gui_pgt(c, s->clients, rock_type);
  return (ERROR);
}

int		take_food(t_server *s, t_client *c)
{
  if (s->map->objects[c->pos->y][c->pos->x]->food == 0)
    return (ERROR);
  s->map->objects[c->pos->y][c->pos->x]->food--;
  c->inventory->food++;
  cmd_gui_pgt(c, s->clients, 0);
  return (SUCCESS);
}

int		cmd_take_object(t_server *s, t_client *c,
				const char *cmd, e_client_type type)
{
  (void)type;
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
