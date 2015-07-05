/*
** show_items_at_position.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server/cmd_ia
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jun 21 20:09:44 2015 Serge Heitzler
** Last update Sat Jul  4 18:47:23 2015 Serge Heitzler
*/

#include "functions.h"

t_objects	g_objects[8] =
  {
    {"nourriture", NULL},
    {"joueur", NULL},
    {"linemate", NULL},
    {"deraumere", NULL},
    {"sibur", NULL},
    {"mendiane", NULL},
    {"phiras", NULL},
    {"thystame", NULL}
  };

int		*get_nb_items(t_block *block)
{
  int		*nb_items;

  nb_items = xmalloc(8 * sizeof(int));
  nb_items[0] = block->food;
  nb_items[1] = block->nb_clients;
  nb_items[2] = block->linemate;
  nb_items[3] = block->deraumere;
  nb_items[4] = block->sibur;
  nb_items[5] = block->mendiane;
  nb_items[6] = block->phiras;
  nb_items[7] = block->thystame;
  return (nb_items);
}

char		*malloc_and_memset(int size_malloc)
{
  char		*final;

  final = xmalloc(sizeof(char) * (size_malloc));
  memset(final, 0, size_malloc);
  return (final);
}

char		*fill_final_string(t_server *s, int size_malloc,
				   int x, int y)
{
  int		i;
  int		total;
  char		*final;
  int		*items;
  t_block	*b;

  i = -1;
  final = malloc_and_memset(size_malloc);
  b = s->map->objects[y][x];
  total = b->food + b->nb_clients + b->linemate + b->deraumere
    + b->sibur + b->mendiane + b->phiras + b->thystame;
  items = get_nb_items(b);
  while (++i < 8)
    {
      x = -1;
      while (++x < items[i])
	{
	  if (total == 1)
	    sprintf(final, "%s%s", final, g_objects[i].label);
	  else
	    sprintf(final, "%s%s ", final, g_objects[i].label);
	  total--;
	}
    }
  return (final);
}

int		get_size_malloc_at_position(t_server* s, int x, int y)
{
  int		total;
  int		size_malloc;
  t_block	*b;

  size_malloc = 0;
  b = s->map->objects[y][x];
  size_malloc = (b->food * (strlen(g_objects[0].label)))
    + (b->nb_clients * (strlen(g_objects[1].label)))
    + (b->linemate * (strlen(g_objects[2].label)))
    + (b->deraumere * (strlen(g_objects[3].label)))
    + (b->sibur * (strlen(g_objects[4].label)))
    + (b->mendiane * (strlen(g_objects[5].label)))
    + (b->phiras * (strlen(g_objects[6].label)))
    + (b->thystame * (strlen(g_objects[7].label)));
  total = b->food + b->nb_clients + b->linemate + b->deraumere
    + b->sibur + b->mendiane + b->phiras + b->thystame;
  if (total > 0)
    size_malloc += total;
  return (size_malloc);
}

char		*show_items_at_position(t_server * s, int x, int y)
{
  int		size_malloc;
  char		*final;

  size_malloc = get_size_malloc_at_position(s, x, y);
  final = fill_final_string(s, size_malloc, x, y);
  return (final);
}
