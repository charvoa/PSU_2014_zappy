/*
** cmd_take_object.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:30:02 2015 Serge Heitzler
** Last update Sun Jul  5 19:33:50 2015 Audibert Louis
*/

#include "functions.h"

int		check_rock(char *rock)
{
  char	**rock_tab;
  int	i;

  rock_tab = xmalloc(7 * sizeof(char *));
  rock_tab[0] = "linemate";
  rock_tab[1] = "deraumere";
  rock_tab[2] = "sibur";
  rock_tab[3] = "mendiane";
  rock_tab[4] = "phiras";
  rock_tab[5] = "thystame";
  rock_tab[6] = NULL;
  i = 0;
  while (rock_tab[i])
    {
      if (strncmp(rock, rock_tab[i], strlen(rock)) == 0)
	{
	  free(rock_tab);
	  return (i);
	}
      i++;
    }
  free(rock_tab);
  return (ERROR);
}

int		launch_func_block(t_block *block,
				  int rock_type,
				  e_flag_rock flag)
{
  int		i;

  i = 0;
  while (i < 6)
    {
      if (i == rock_type)
	{
	  if (g_rocks[i].ptr_func(block, flag) == SUCCESS)
	    return (SUCCESS);
	  return (ERROR);
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
  if (launch_func_block(s->map->objects[c->pos->y][c->pos->x],
			rock_type, REMOVE) == ERROR)
    return (ERROR);
  if (launch_func_inventory(c, rock_type, ADD) == ERROR)
    return (ERROR);
  cmd_pgt(c, s->clients, rock_type + 1);
  cmd_pin(s, c, "protocole", GUI);
  cmd_bct(s, c, "protocole", GUI);
  return (SUCCESS);
}

int		take_food(t_server *s, t_client *c)
{
  if (s->map->objects[c->pos->y][c->pos->x]->food <= 0)
    return (ERROR);
  s->map->objects[c->pos->y][c->pos->x]->food--;
  c->inventory->food++;
  cmd_pgt(c, s->clients, 0);
  cmd_pin(s, c, "protocole", GUI);
  cmd_bct(s, c, "protocole", GUI);
  return (SUCCESS);
}

int		cmd_take_object(t_server *s, t_client *c,
				char *cmd, e_client_type type)
{
  (void)type;
  char		*item;

  if (c->state == CHILD)
    return (ERROR);
  item = xmalloc((strlen(cmd) - 5) * sizeof(char));
  bzero(item, strlen(cmd) - 5);
  sscanf(cmd, "prend %s", item);
  if (do_take_object(s, c, item) == ERROR)
    return (ERROR);
  send_data(c->fd, "ok\n");
  return (SUCCESS);
}
