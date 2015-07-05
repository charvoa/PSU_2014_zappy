/*
** check_end_game.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Wed Jul  1 11:14:16 2015 Audibert Louis
** Last update Sun Jul  5 19:19:04 2015 Audibert Louis
*/

#include "functions.h"

void		end_the_game(t_server *s, char *name)
{
  printf("Team %s Won !\n", name);
  cmd_seg(s->clients, name);
  sleep(5);
  exit(0);
}

void		check_end_game(t_server *s)
{
  t_node	*tmp_team;
  t_node	*tmp_client;
  t_team	*team;
  t_client	*client;

  tmp_team = s->teams->start;
  while (tmp_team)
    {
      team = tmp_team->data;
      team->pro = 0;
      tmp_client = s->clients->start;
      while (tmp_client)
	{
	  client = tmp_client->data;
	  if (client->type == IA)
	    if (client->level == 8
		&& strcmp(client->team_name, team->name) == 0)
	      team->pro++;
	  tmp_client = tmp_client->next;
	}
      if (team->pro >= 6)
	end_the_game(s, team->name);
      tmp_team = tmp_team->next;
    }
}
