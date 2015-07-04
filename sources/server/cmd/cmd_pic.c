/*
** cmd_pic.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jun 28 23:26:08 2015 Serge Heitzler
** Last update Fri Jul  3 19:35:54 2015 Serge Heitzler
*/

#include "functions.h"

int		*get_fds(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  (void)cmd;
  (void)type;
  int		*res;
  t_client	*cli;
  t_block	*b;
  int		i;
  int		o;

  i = 0;
  o = 0;
  res = xmalloc(sizeof(int) * (g_incantation[c->level - 1].player - 1));
  b = s->map->objects[c->pos->y][c->pos->x];
  while (i < b->nb_clients)
    {
      cli = get_client_by_id(s->clients, b->ids[i]);
      if (cli->level == c->level && cli->fd != c->fd)
	{
	  res[o] = cli->fd;
	  o++;
	}
      i++;
    }
  return (res);
}

char		*get_other_fds(t_server *s, t_client *c,
			       char *cmd, e_client_type type)
{
  int		size_malloc;
  char		*final;
  int		*fds;
  int		i;

  i = 0;
  size_malloc = 0;
  fds = get_fds(s, c, cmd, type);
  while (i < g_incantation[c->level - 1].player - 1)
    {      
      size_malloc += (2 + istm(fds[i]));
      i++;
    }
  i = 1;
  final = xmalloc(sizeof(char) * size_malloc);
  bzero(final, size_malloc);
  sprintf(final, " #%d", fds[0]);
  while (i < g_incantation[c->level - 1].player - 1)
    {
      sprintf(final, "%s #%d", final, fds[i]);
      i++;
    }
  return (final);
}

int		cmd_pic(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  (void)cmd;
  (void)type;
  char		*tmp;
  char		*final;
  int		size_malloc;

  size_malloc = 10 + istm(c->pos->x) + istm(c->pos->y) + istm(c->level) + istm(c->fd);
  if (c->level > 1)
    {
      tmp = get_other_fds(s, c, cmd, type);
      size_malloc += strlen(tmp);
    }
  final = xmalloc(sizeof(char) * size_malloc);
  bzero(final, size_malloc);
  if (c->level > 1)
    sprintf(final, "pic %d %d %d #%d%s\n", c->pos->x, c->pos->y, c->level, c->fd, tmp);
  else
    sprintf(final, "pic %d %d %d #%d\n", c->pos->x, c->pos->y, c->level, c->fd);
  send_data_to_gui(s->clients, final);
  free(tmp);
  free(final);
  return (SUCCESS);
}
