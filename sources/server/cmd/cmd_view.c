/*
** cmd_view.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:30:07 2015 Serge Heitzler
** Last update Tue Jun 23 20:28:28 2015 Serge Heitzler
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

int		determine_pos_x(t_client *c, t_size *size, int t, int l)
{
  (void)size;
  if (c->orientation == UP)
    return (c->pos->x + t);
  if (c->orientation == RIGHT)
    return (c->pos->x + l);
  if (c->orientation == DOWN)
    return (c->pos->x - t);
  if (c->orientation == LEFT)
    return (c->pos->x - l);
  return (SUCCESS);
}

int		determine_pos_y(t_client *c, t_size *size, int t, int l)
{
  (void)size;
  if (c->orientation == UP)
    return (c->pos->y + l);
  if (c->orientation == RIGHT)
    return (c->pos->y + t);
  if (c->orientation == DOWN)
    return (c->pos->y - l);
  if (c->orientation == LEFT)
    return (c->pos->y - t);
  return (SUCCESS);
}

char		**write_pos_in_array(t_server *s, t_client *c, int i, unsigned int l)
{
  char		**pos;
  int		nb_visible_space;
  unsigned int 	t;
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
  pos[0] = xmalloc(sizeof(char) * (istm((int)c->pos->x) + istm((int)c->pos->y) + 2));
  memset(pos[0], 0, istm((int)c->pos->x) + istm((int)c->pos->y) + 2);
  sprintf(pos[0], "%d %d", (int)c->pos->x, (int)c->pos->y);
  pos[nb_visible_space + 1] = NULL;
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
  while (i < get_number_of_visible_space(c->level))
    {
      sscanf(pos[i], "%d %d", x, y);
      if (size_malloc += (get_size_malloc_at_position(s, *x, *y)) == 0)
	size_malloc++;
      i++;
    }
  return (SUCCESS);
}
