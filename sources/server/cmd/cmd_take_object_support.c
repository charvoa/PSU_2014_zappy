/*
** cmd_take_object_support.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server/cmd
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sun Jul  5 19:33:31 2015 Audibert Louis
** Last update Sun Jul  5 19:34:00 2015 Audibert Louis
*/

#include "functions.h"

int		do_take_object(t_server *s, t_client *c, char *item)
{
  if (strcmp(item, "nourriture") == 0)
    {
      if (take_food(s, c) == ERROR)
	{
	  send_data(c->fd, "ko\n");
	  return (ERROR);
	}
    }
  else
    {
      if (take_rock(s, c, item) == ERROR)
	{
	  send_data(c->fd, "ko\n");
	  return (ERROR);
	}
    }
  return (SUCCESS);
}
