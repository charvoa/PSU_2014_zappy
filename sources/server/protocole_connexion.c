/*
** protocole_connexion.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
**
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
**
** Started on  Sat Jun 27 14:38:32 2015 Audibert Louis
** Last update Sun Jul  5 19:43:25 2015 Audibert Louis
*/

#include "functions.h"

void	protocole_graphique(t_server *s, t_client *c)
{
  cmd_msz(s, c, "protocole", NORMAL);
  cmd_sgt(s, c, "protocole", NORMAL);
  cmd_mct(s, c, "protocole", NORMAL);
  cmd_tna(s, c, "protocole", NORMAL);
  cmd_pnw_all(s, c, "protocole", GUI);
  cmd_enw_all(s, c, GUI);
}

int		protocole_connexion(t_server *s, int fd)
{
  char		*tmp;
  t_client	*client;
  int		nb;

  send_data(fd, "BIENVENUE\n");
  tmp = xmalloc(1024 * sizeof(char));
  bzero(tmp, 1024);
  if ((nb = read(fd, tmp, 1024) > 0))
    {
      client = get_client_by_id(s->clients, fd);
      if (cmd_team(s, client, tmp, NORMAL) == ERROR)
	return (ERROR);
    }
  else
    {
      send_data(fd, "ko\n");
      return (ERROR);
    }
  return (SUCCESS);
}
