/*
** cmd_view_support.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Thu Jul  2 11:15:48 2015 Serge Heitzler
** Last update Sat Jul  4 14:29:58 2015 Serge Heitzler
*/

#include "functions.h"

char		*create_final_support(t_server *s, t_client *c,
				      char **pos, char *final)
{
  char		*tmp;
  int		*x;
  int		*y;
  int		i;
  int		size;

  i = 0;
  x = xmalloc(sizeof(int));
  y = xmalloc(sizeof(int));
  while (++i < get_number_of_visible_space(c->level))
    {
      sscanf(pos[i], "%d %d", x, y);
      size = get_size_malloc_at_position(s, *x, *y);
      tmp = xmalloc(sizeof(char) * size);
      bzero(tmp, size);
      tmp = show_items_at_position(s, *x, *y);
      if (i == (get_number_of_visible_space(c->level) - 1) && size != 0)
      	sprintf(final, "%s %s", final, tmp);
      else if (size == 0)
  	sprintf(final, "%s,", final);	
      else
  	sprintf(final, "%s %s,", final, tmp);
      free(tmp);
    }
  return (final);
}

int		malloc_cmd_view(t_server *s, t_client *c,
				char **pos)
{
  int		i;
  int		*x;
  int		*y;
  int		size_malloc;

  i = 0;
  size_malloc = 0;
  x = xmalloc(sizeof(int));
  y = xmalloc(sizeof(int));
  while (i < get_number_of_visible_space(c->level))
    {
      sscanf(pos[i], "%d %d", x, y);
      size_malloc += (get_size_malloc_at_position(s, *x, *y));
      if (get_size_malloc_at_position(s, *x, *y) == 0)
	size_malloc++;
      i++;
    }
  size_malloc += 3;
  return (size_malloc);
}

