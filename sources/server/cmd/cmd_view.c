/*
** cmd_view.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:30:07 2015 Serge Heitzler
** Last update Sun Jul  5 19:37:28 2015 Audibert Louis
*/

#include "functions.h"

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

char		**write_pos_in_array(t_server *s, t_client *c, int i, int l)
{
  char		**pos;
  int		nb_visible_space;
  int	 	t;
  int		x;
  int		y;

  nb_visible_space = get_number_of_visible_space(c->level);
  pos = xmalloc(sizeof(char *) * (nb_visible_space + 1));
  while (i < nb_visible_space)
    {
      while (l <= c->level)
	{
	  t = (l * (-1)) - 1;
	  while (++t <= l)
	    {
	      x = determine_pos_x(c, s->map->size, t, l);
	      y = determine_pos_y(c, s->map->size, t, l);
	      pos[i] = xmalloc(sizeof(char) * (istm(x) + istm(y) + 2));
	      memset(pos[i], 0, istm(x) + istm(y) + 2);
	      sprintf(pos[i++], "%d %d", x, y);
	    }
	  l++;
	}
    }
  return (pos);
}

char		**get_pos_of_visible_space(t_server *s, t_client *c)
{
  (void)s;
  char		**pos;
  int		nb_visible_space;

  nb_visible_space = get_number_of_visible_space(c->level);
  pos = write_pos_in_array(s, c, 1, 1);
  pos[0] = xmalloc(sizeof(char) *
		   (istm((int)c->pos->x) + istm((int)c->pos->y) + 2));
  memset(pos[0], 0, istm((int)c->pos->x) + istm((int)c->pos->y) + 2);
  sprintf(pos[0], "%d %d", (int)c->pos->x, (int)c->pos->y);
  pos[nb_visible_space] = NULL;
  return (pos);
}

char		*create_final_string_view(t_server *s, t_client *c,
					  int size_malloc, char **pos)
{
  char		*final;
  char		*tmp;
  int		*x;
  int		*y;
  int		size;

  final = xmalloc(sizeof(char) * (size_malloc));
  bzero(final, size_malloc);
  x = xmalloc(sizeof(int));
  y = xmalloc(sizeof(int));
  sscanf(pos[0], "%d %d", x, y);
  size = get_size_malloc_at_position(s, *x, *y);
  tmp = malloc_and_memset(size);
  tmp = show_items_at_position(s, *x, *y);
  sprintf(final, "%s,", tmp);
  free(tmp);
  final = create_final_support(s, c, pos, final);
  return (final);
}

int		cmd_view(t_server *s, t_client *c,
			 char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  int		size_malloc;
  char		**pos;
  char		*final;
  char		*tmp;

  if (c->state == CHILD)
    return (ERROR);
  pos = get_pos_of_visible_space(s, c);
  size_malloc = malloc_cmd_view(s, c, pos);
  tmp = create_final_string_view(s, c, size_malloc, pos);
  size_malloc += 4;
  final = xmalloc(sizeof(char) * (size_malloc));
  bzero(final, size_malloc);
  sprintf(final, "{%s}\n", tmp);
  send_data(c->fd, final);
  free(final);
  free(tmp);
  return (SUCCESS);
}
