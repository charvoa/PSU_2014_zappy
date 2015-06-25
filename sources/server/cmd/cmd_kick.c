/*
** cmd_expel.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:12 2015 Serge Heitzler
** Last update Thu Jun 25 12:33:31 2015 Audibert Louis
*/

#include "server.h"

/* char		*get_trame_deplacement(t_client *c) */
/* { */
/*   char		*cmd; */

/*   cmd = xmalloc((strlen("deplacement: ") + ) * sizeof(char)); */
/*   send_data(client->fd, strcat("deplacement: ", c->orientation)); */

/* } */

int		cmd_kick(t_server *s, t_client *c, const char *cmd)
{
  (void)s;
  (void)c;
  (void)cmd;

  //PARCOURIR S->MAPS[Y][X]->OBJECTS == PLAYER && != CLIENT *C
  //ET DU COUP SEND_DATA TO EVERYBODY "deplacement: direction = orientation t_client *c
  /* t_node	*tmp; */
  /* t_client	*client; */
  /* char		*final; */
  /* char		*cmd; */

  /* client = xmalloc(sizeof(t_client)); */
  /* tmp = s->map->objects[c->pos->y][c->pos->x]->start; */
  /* final = get_trame_deplacement(c); */
  /* while (tmp) */
  /*   { */
  /*     if (tmp->type == PLAYER) */
  /* 	{ */
  /* 	  client = tmp->data; */
  /* 	  if ((client->pos->x == c->pos->x) && (client->pos->y == c->pos->x) */
  /* 	      && client->fd != c->fd) */
  /* 	    { */
  /* 	      send_data(client->fd, final); */
  /* 	    } */
  /* 	} */
  /*     tmp = tmp->next; */
  /*   } */
  return (SUCCESS);
}
