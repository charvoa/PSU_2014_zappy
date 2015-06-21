/*
** cmd_view.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:30:07 2015 Serge Heitzler
** Last update Sun Jun 21 23:04:00 2015 Serge Heitzler
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

char		**get_pos_of_visible_space(t_client *c)
{
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
      // determiner x et y correct
      // avec une fonction de type func(t_client(pos, ori), size, i);
      x = 0;
      y = 0;
      pos[i] = xmalloc(sizeof(char) * (int_size_to_malloc(x) + int_size_to_malloc(y) + 2));
      
      i++;
    }
  return (pos);
}

int		cmd_view(t_server *s, t_client *c, const char *cmd)
{
  (void)cmd;
  // Les (void) du dessous sont à supprimer, celui du dessus est important et à laisser.
  (void)s;
  (void)c;
  int		i;
  int		*x;
  int		*y;
  int		size_malloc;
  char		**pos;

  i = 0;
  pos = get_pos_of_visible_space(c);
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
