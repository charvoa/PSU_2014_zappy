/*
** protocole_connexion.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 14:38:32 2015 Audibert Louis
** Last update Sat Jun 27 15:05:02 2015 Audibert Louis
*/

#include "functions.h"

static void	protocole_graphique(t_server *s, t_list *clients, int fd)
{
  char		*trame;
  
  trame = xmalloc(64 * sizeof(char));
  sprintf(trame, "msz %d %d\n", s->map->width, s->map->height);
  send_data(clients, str);
  bzero(trame, 64);
  
}

void		protocole_connexion(t_server *s, int fd)
{
  char	*tmp;
  t_client	*client;
  int	nb;

  send_data(fd, "BIENVENUE\n");
  tmp = xmalloc(1024 * sizeof(char));
  bzero(tmp, 1024);
  if ((nb = read(fd, tmp, 1024) > 0))
    {
      client = get_client_by_id(s->clients, fd);
      cmd_team(s, client, tmp);
    }
  else
    send_data(fd, "ko\n");
}
