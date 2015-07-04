/*
** cmd_tin.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jul  4 18:48:13 2015 Audibert Louis
** Last update Sat Jul  4 20:52:30 2015 Audibert Louis
*/

#include "functions.h"

int		get_nb_players_by_team(t_list *clients, char *team_name)
{
  t_node	*tmp;
  t_client	*client;
  int		nb;

  nb = 0;
  tmp = clients->start;
  while (tmp)
    {
      client = tmp->data;
      if (client->type == IA)
	{
	  if (strcmp(client->team_name, team_name) == 0)
	    nb++;
	}
      tmp = tmp->next;
    }
  return (nb);
}

int		get_nb_players_lvl_8_by_team(t_list *clients, char *team_name)
{
  t_node	*tmp;
  t_client	*client;
  int		nb;

  nb = 0;
  tmp = clients->start;
  while (tmp)
    {
      client = tmp->data;
      if (client->type == IA)
	{
	  if ((strcmp(client->team_name, team_name) == 0) && client->level == 8)
	    nb++;
	}
      tmp = tmp->next;
    }
  return (nb);
}

int		cmd_tin(t_server *s, t_client *c, char *cmd, e_client_type type)
{
  (void)type;
  char		*team;
  char		*trame;
  int		nb_players;
  int		nb_players_lvl_8;

  nb_players = 0;
  nb_players_lvl_8 = 0;
  team = xmalloc((strlen(cmd) - 3) * sizeof(char));
  bzero(team, strlen(cmd) - 3);
  sscanf(cmd, "tin %s", team);
  printf("TEAM = %s\n", team);
  nb_players = get_nb_players_by_team(s->clients, team);
  nb_players_lvl_8 = get_nb_players_lvl_8_by_team(s->clients, team);
  trame = malloc_and_memset((8 + strlen(team)
		   + istm(nb_players)
		   + istm(nb_players_lvl_8)) * sizeof(char));
  sprintf(trame, "tin %s %d %d\n", team, nb_players, nb_players_lvl_8);
  printf("trame = %s", trame);
  send_data(c->fd, trame);
  free(trame);
  return (SUCCESS);
}
