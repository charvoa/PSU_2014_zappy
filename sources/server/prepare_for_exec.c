/*
** prepare_for_exec.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 26 08:23:46 2015 Serge Heitzler
** Last update Sat Jun 27 10:56:03 2015 Audibert Louis
*/

#include "functions.h"

static void	check_client_type(const char *cmd, t_client *c)
{
  if (!strcmp(cmd, "graph_cli_connected\r\n"))
    c->type = GUI;
}

void		prepare_for_exec(t_server *s, t_client *c)
{
  (void)s;
  int			ret;
  t_cmd			*s_cmd;

  clock_gettime(CLOCK_REALTIME, &s->now);
  if (c->cmds->length >= 10)
    {
      send_data(c->fd, "Cmd list is too long !\n");
      return;
    }

  s_cmd = xmalloc(sizeof(t_cmd));
  s_cmd->label = ring_buffer_get_next_command(c->buffer);
  check_client_type(s_cmd->label, c);


  if (s_cmd->label == NULL)
    return;





  (void)ret;
  /* if (ret = (is_cmd(s_cmd->label)) != NO) */
  /*   g_cmds[ret].delay; */
  // INIT Obligatoire de exec_at pour éviter erreur valgrind
  clock_gettime(CLOCK_REALTIME, &s_cmd->exec_at);



  //  now.tv_sec;  /* seconds */
  //  now.tv_usec; /* nanoseconds divide by 1000 to get microseconds*/

  
  push_back(c->cmds, s_cmd, CMD);
  printf("CMD == %s\n", s_cmd->label);
}
