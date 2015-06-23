/*
** cmd_broadcast.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:29 2015 Serge Heitzler
** Last update Tue Jun 23 14:15:06 2015 Audibert Louis
*/

#include "server.h"

char		*trunc_broadcast(char *text, const char *cmd)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (cmd[i])
    {
      if (i >= 10)
	{
	  text[j] = cmd[i];
	  j++;
	}
      i++;
    }
  text[j] = '\0';
  return (text);
}

int		cmd_broadcast(t_server *s, t_client *c, const char *cmd)
{
  // Les (void) du dessous sont à supprimer, celui du dessus est important et à laisser.
  (void)s;
  (void)c;
  (void)cmd;
  char			*text;
  t_node		*tmp;
  t_client		*c_iterate;

  tmp = s->clients->start;
  text = xmalloc((strlen(cmd) - 9) * sizeof(char));
  bzero(text, strlen(cmd) - 9);
  text = trunc_broadcast(text, cmd);
  printf("text = %s\n", text);
  c_iterate = xmalloc(sizeof(t_client));
  c_iterate = tmp->data;
  while (tmp)
    {
      c_iterate = tmp->data;
      send_data(c_iterate->fd, text);
      tmp = tmp->next;
    }
  return (SUCCESS);
}
