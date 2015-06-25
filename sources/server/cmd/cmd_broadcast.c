/*
** cmd_broadcast.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:29 2015 Serge Heitzler
** Last update Thu Jun 25 14:37:07 2015 Audibert Louis
*/

#include "server.h"

char		*get_trame_broadcast(t_client *c, char *text)
{
  char		*final;
  
  final = xmalloc((strlen("message ") + strlen(text) + 8) * sizeof(char));
  bzero(final, (strlen("message ") + strlen(text) + 8));
  sprintf(final, "message %d %d,%s\n", c->pos->y, c->pos->x, text);
  printf("final = %s", final);
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
void		get_text(char *text, const char *cmd)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (cmd[i])
    {
      if (i > 9)
	{
	  text[j] = cmd[i];
	  j++;
	}
      i++;
    }
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
  get_text(text, cmd);
  printf("text = %s\n", text);
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
