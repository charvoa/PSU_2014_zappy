/*
** cmd_pbc.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jun 28 23:30:52 2015 Serge Heitzler
** Last update Wed Jul  1 12:46:55 2015 Serge Heitzler
*/

#include "functions.h"

/* int		case_l_superior(t_position *f_pos, t_position *s_pos) */
/* { */
/*   if (c->orientation == NORD) */
/*     return (); */
/*   else if (c->orientation == EST) */
/*     ; */
/*   else if (c->orientation == SUD) */
/*     ; */
/*   else */
/*     ; */
/* } */

/* int		case_l_inferior(t_position *f_pos, t_position *s_pos) */
/* { */
/*   if (c->orientation == NORD) */
/*     ; */
/*   else if (c->orientation == EST) */
/*     ; */
/*   else if (c->orientation == SUD) */
/*     ; */
/*   else */
/*     ; */
/* } */

/* int		case_l_equal(t_position *f_pos, t_position *s_pos) */
/* { */
/*   if (c->orientation == NORD) */
/*     return (f_pos->x < s_pos->x ? 8 : 6); */
/*   else if (c->orientation == EST) */
/*     return (f_pos->y < s_pos->y ? 8 : 6);     */
/*   else if (c->orientation == SUD) */
/*     return (f_pos->x < s_pos->x ? 8 : 6); */
/*   else */
/*     ; */
/* } */

/* int		determine_last_case(t_client *c, int l, int w, t_position *pos) */
/* { */
/*   if (l > w) */
/*     return (case_l_superior(c, l, w, pos)); */
/*   else if (l < w) */
/*     return (case_l_inferior(c, l, w, pos)); */
/*   else */
/*     return (case_l_equal(c, l, w, pos)); */
/* } */

int		cmd_pbc(t_server *s, t_client *c,
			char *cmd, e_client_type type)
{
  (void)s;
  (void)c;
  (void)cmd;
  (void)type;
  t_node	*tmp_n;
  t_client	*cli;
  char		*tmp;
  char		*request;
  int		sound;
  int		size_malloc;
  int		l;
  int		w;

  request = xmalloc(sizeof(char) * (strlen(cmd) - 10));
  bzero(request, (strlen(cmd) - 10));
  sscanf(cmd, "broadcast %4050[^\n]", request);
  cli = xmalloc(sizeof(t_client));
  tmp_n = s->clients->start;
  sound = 0;
  (void)l;
  (void)w;
  while (tmp_n)
    {
      cli = tmp_n->data;
      if (cli->state == ADULT)
	{
	  l = get_l(s->map, c->pos->x, cli->pos->x);
	  w = get_w(s->map, c->pos->y, cli->pos->y);
	  //	  sound = determine_last_case(c, l, w, cli->pos);
	  size_malloc = 10 + istm(sound) + strlen(request);
	  tmp = xmalloc(sizeof(char) * size_malloc);
	  bzero(tmp, size_malloc);
	  sprintf(tmp, "message %d, %s", sound, request);
	  send_data(cli->fd, tmp);
	}
      tmp_n = tmp_n->next;
    }
  return (SUCCESS);
}
