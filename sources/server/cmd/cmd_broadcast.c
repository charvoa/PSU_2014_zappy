/*
** cmd_broadcast.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:29 2015 Serge Heitzler
** Last update Sun Jul  5 19:30:31 2015 Audibert Louis
*/

#include "functions.h"

int		case_l_superior(t_client *c,
				t_client *cli, int l, int w)
{
  (void)w;
  if (cli->orientation == NORD)
    return (c->pos->x + l == cli->pos->x ?
	    (3) : (c->pos->x - l == cli->pos->x ?
		   7 : (c->pos->x - l < 0 ? 7 : 3)));
  else if (cli->orientation == EST)
    return (c->pos->x + l == cli->pos->x ?
	    (5) : (c->pos->x - l == cli->pos->x ?
		   1 : (c->pos->x - l < 0 ? 1 : 5)));
  else if (cli->orientation == SUD)
    return (c->pos->x + l == cli->pos->x ?
	    (7) : (c->pos->x - l == cli->pos->x ?
		   3 : (c->pos->x - l < 0 ? 3 : 7)));
  else
    return (c->pos->x + l == cli->pos->x ?
	    (1) : (c->pos->x - l == cli->pos->x ?
		   5 : (c->pos->x - l < 0 ? 5 : 1)));
}

int		case_l_inferior(t_client *c,
				t_client *cli, int l, int w)
{
  (void)l;
  if (cli->orientation == NORD)
    return (c->pos->y + w == cli->pos->y ?
	    (1) : (c->pos->y - w == cli->pos->y ?
		   5 : (c->pos->y - w < 0 ? 5 : 1)));
  else if (cli->orientation == EST)
    return (c->pos->y + w == cli->pos->y ?
	    (3) : (c->pos->y - w == cli->pos->y ?
		   7 : (c->pos->y - w < 0 ? 7 : 3)));
  else if (cli->orientation == SUD)
    return (c->pos->y + w == cli->pos->y ?
	    (5) : (c->pos->y - w == cli->pos->y ?
		   1 : (c->pos->y - w < 0 ? 1 : 5)));
  else
    return (c->pos->y + w == cli->pos->y ?
	    (7) : (c->pos->y - w == cli->pos->y ?
		   3 : (c->pos->y - w < 0 ? 3 : 7)));
}

int		case_l_equal(t_client *c,
			     t_client *cli, int l, int w)
{
  (void)l;
  (void)w;
  if (cli->pos->x == c->pos->x && cli->pos->y == c->pos->y)
    return (0);
  else if (cli->orientation == NORD)
    return (c->pos->x > cli->pos->x ?
	    (c->pos->y > cli->pos->y ? 6 : 8) :
	    (c->pos->y > cli->pos->y ? 4 : 2));
  else if (cli->orientation == EST)
    return (c->pos->x > cli->pos->x ?
	    (c->pos->y > cli->pos->y ? 8 : 2) :
	    (c->pos->y > cli->pos->y ? 6 : 4));
  else if (cli->orientation == SUD)
    return (c->pos->x > cli->pos->x ?
	    (c->pos->y > cli->pos->y ? 2 : 4) :
	    (c->pos->y > cli->pos->y ? 8 : 6));
  else
    return (c->pos->x > cli->pos->x ?
	    (c->pos->y > cli->pos->y ? 4 : 6) :
	    (c->pos->y > cli->pos->y ? 2 : 8));
}

int		determine_last_case(t_client *c,
				    t_client *cli, int l, int w)
{
  if (l > w)
    return (case_l_superior(c, cli, l, w));
  else if (l < w)
    return (case_l_inferior(c, cli, l, w));
  else
    return (case_l_equal(c, cli, l, w));
}

int		cmd_broadcast(t_server *s, t_client *c,
			      char *cmd, e_client_type type)
{
  char		*msg;
  t_node	*tmp_n;
  t_client	*cli;

  if (c->state == CHILD)
    return (ERROR);
  msg = xmalloc(sizeof(char) * (strlen(cmd) - 9));
  bzero(msg, (strlen(cmd) - 9));
  sscanf(cmd, "broadcast %4050[^\n]", msg);
  tmp_n = s->clients->start;
  while (tmp_n)
    {
      cli = tmp_n->data;
      if (cli->state == ADULT && cli->type == IA && cli->fd != c->fd)
	generate_broadcast(s, c, cli, msg);
      tmp_n = tmp_n->next;
    }
  cmd_pbc(s, c, cmd, type);
  free(msg);
  return (SUCCESS);
}
