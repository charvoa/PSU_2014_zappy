/*
** show_items_at_position.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server/cmd_ia
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jun 21 20:09:44 2015 Serge Heitzler
** Last update Fri Jun 26 13:31:57 2015 Serge Heitzler
*/

#include "server.h"

t_objects	g_objects[8] =
  {
    {"food", &create_food},
    {"player", NULL},
    {"limemate", &create_rock},
    {"deraumere", &create_rock},
    {"sibur", &create_rock},
    {"mendiane", &create_rock},
    {"phiras", &create_rock},
    {"thystame", &create_rock}
  };

int		*get_nb_items(t_block *block)
{
  int		*nb_items;

  nb_items = xmalloc(8 * sizeof(int));
  nb_items[0] = block->food;
  nb_items[1] = block->nb_clients;
  nb_items[2] = block->limemate;
  nb_items[3] = block->deraumere;
  nb_items[4] = block->sibur;
  nb_items[5] = block->mendiane;
  nb_items[6] = block->phiras;
  nb_items[7] = block->thystame;
  return (nb_items);
}

int		get_last_wrote(int *nb_items)
{
  int		i;

  i = 7;
  while (i >= 0 && nb_items[i] == 0)
    i++;
  return (i);
}

char		*fill_final_string(int size_malloc, int *nb_items)
{
  int		i;
  char		*final;

  i = -1;
  final = xmalloc(sizeof(char) * (size_malloc));
  memset(final, 0, size_malloc);
  while (++i <= get_last_wrote(nb_items))
    {
      if (nb_items[i] > 0)
	{
	  if (i == get_last_wrote(nb_items))
	    {
	      strcat(final, g_objects[i].label);
	      sprintf(final, "%s %d\n", final, nb_items[i]);
	    }
	  else
	    {
	      strcat(final, g_objects[i].label);
	      sprintf(final, "%s %d, ", final, nb_items[i]);
	    }
	}
    }
  return (final);
}

// free list
int		get_size_malloc_at_position(t_server* s, int x, int y)
{
  int		i;
  int		*nb_items;
  int		size_malloc;
  t_block	*block;

  i = 0;
  size_malloc = 0;
  block = s->map->objects[y][x];
  nb_items = get_nb_items(block);
  while (i < 8)
    {
      if (nb_items[i] > 0 && i == get_last_wrote(nb_items))
	size_malloc += (strlen(g_objects[i].label) + 1 + istm(nb_items[i]) + 1);
      else if (nb_items[i] > 0)
	size_malloc += (strlen(g_objects[i].label) + 1 + istm(nb_items[i]) + 2);
      i++;
    }
  return (size_malloc);
}

char		*show_items_at_position(t_server * s, int x, int y)
{
  int		*nb_items;
  int		size_malloc;
  t_block	*block;
  char		*final;

  block = s->map->objects[y][x];
  nb_items = get_nb_items(block);
  size_malloc = get_size_malloc_at_position(s, x, y);
  final = fill_final_string(size_malloc, nb_items);
  return (final);
}
