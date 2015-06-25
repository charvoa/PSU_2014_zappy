/*
** cmd_broadcast.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:29 2015 Serge Heitzler
** Last update Thu Jun 25 14:16:00 2015 Audibert Louis
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

void		get_text(char *text, const char *cmd)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (cmd[i])
    {
      if (i >= 9)
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
  /* sscanf(cmd, "broadcast %s", text); */
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
  return (SUCCESS);
}
