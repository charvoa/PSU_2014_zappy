/*
** cmd_broadcast.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:29 2015 Serge Heitzler
** Last update Thu Jun 25 03:10:15 2015 Antoine Garcia
*/

#include "server.h"

char		*get_trame_broadcast(t_client *c, char *text)
{
  char		x[3];
  char		y[3];
  char		*final;

  sprintf(x, "%d", c->pos->x);
  sprintf(y, "%d", c->pos->y);
  final = xmalloc((strlen("message ") + strlen(x) + strlen(y)
		   + strlen(text) + 2) * sizeof(char));
  bzero(final, (strlen("message ") + strlen(x) + strlen(y)
		+ strlen(text) + 2));
  sprintf(final, "message %s %s,%s\n", x, y, text);
  printf("final = %s\n", final);
  return (final);
}

static void	send_gui_broadcast(char *msg, t_list *clients, t_client *c)
{
  char	*str;

  str = xmalloc((strlen(msg) + 50) * sizeof(char));
  sprintf(str, "pbc #%d %s\n", c->fd, msg);
  printf("gui_broadcast = %s\n", str);
  send_data_to_gui(clients, str);
}

int		cmd_broadcast(t_server *s, t_client *c, const char *cmd)
{
  // Les (void) du dessous sont à supprimer, celui du dessus est important et à laisser.
  (void)c;
  char			*text;
  char			*final;
  t_node		*tmp;
  t_client		*c_iterate;

  tmp = s->clients->start;
  text = xmalloc((strlen(cmd) - 9) * sizeof(char));
  bzero(text, strlen(cmd) - 9);
  sscanf(cmd, "broadcast %s", text);
  printf("text = %s", text);
  final = get_trame_broadcast(c, text);
  c_iterate = xmalloc(sizeof(t_client));
  c_iterate = tmp->data;
  while (tmp)
    {
      c_iterate = tmp->data;
      send_data(c_iterate->fd, final);
      tmp = tmp->next;
    }
  send_gui_broadcast(text, s->clients, c);
  return (SUCCESS);
}
