/*
** cmd_view.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:30:07 2015 Serge Heitzler
** Last update Mon Jun 22 14:39:30 2015 Serge Heitzler
*/

#include "server.h"

int		get_number_of_visible_space(unsigned int level)
{
  int		nb;

  nb = 1;
  while (level >= 1)
    {
      nb += ((level * 2) + 1);
      level--;
    }
  return (nb);
}

/* int		determine_pos_x(t_client *c, t_size *size, int i) */
/* { */
/*   int		res; */
/*   return (res); */
/* } */

char		**get_pos_of_visible_space(t_server *s, t_client *c)
{
  (void)s;
  int		i;
  int		x;
  int		y;
  int		nb_visible_space;
  char		**pos;

  i = 0;
  nb_visible_space = get_number_of_visible_space(c->level);
  pos = xmalloc(sizeof(char *) * nb_visible_space);
  while (i < nb_visible_space)
    {
      x = 0;
      y = 0;
      //x = determine_pos_x(c, s->map->size, i);
      //y = determine_pos_y(c, s->map->size, i);
      pos[i] = xmalloc(sizeof(char) * (int_size_to_malloc(x) + int_size_to_malloc(y) + 2));
      
      i++;
    }
  return (pos);
}

int		cmd_view(t_server *s, t_client *c, const char *cmd)
{
  (void)cmd;
  int		i;
  int		*x;
  int		*y;
  int		size_malloc;
  char		**pos;

  i = 0;
  pos = get_pos_of_visible_space(s, c);
  size_malloc = 0;
  x = xmalloc(sizeof(int));
  y = xmalloc(sizeof(int));
  // il risque d'y avoir des invalids read a cause des virgules manquantes dans les malloc

  while (i < get_number_of_visible_space(c->level))
    {
      sscanf(pos[i], "%d %d", x, y);
      if (size_malloc += (get_size_malloc_at_position(s, *x, *y)) == 0)
	size_malloc++;
    }


  return (SUCCESS);
}
