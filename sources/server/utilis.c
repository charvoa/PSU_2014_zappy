/*
** utilis.c for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:38:51 2015 Nicolas Charvoz
** Last update Sat Jun 27 10:55:56 2015 Audibert Louis
*/

#include "functions.h"

void	init_socket(t_server *s)
{
  int	yes;

  yes = 1;
  FD_ZERO(&s->master);
  FD_ZERO(&s->read_fds);
  s->listener = xsocket(AF_INET, SOCK_STREAM, 0);
  g_listener = s->listener;
  printf("Server-socket() is OK ... \n");
  if (setsockopt(s->listener, SOL_SOCKET, SO_REUSEADDR, &yes,
		 sizeof(int)) == -1)
    {
      perror("Server-setsockopt() erro !");
      exit(1);
    }
  printf("Server-setsockopt() is OK ... \n");
}

void	bind_socket(t_server *s, int port)
{
  s->serveraddr.sin_family = AF_INET;
  s->serveraddr.sin_addr.s_addr = INADDR_ANY;
  s->serveraddr.sin_port = htons(port);
  memset(&(s->serveraddr.sin_zero), '\0', 8);
  xbind(s->listener, (struct sockaddr *)&(s->serveraddr),
	sizeof(s->serveraddr));
  printf("Server-bind() is OK ...\n");
}

void	protocole_connexion(t_server *s, int fd)
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

void	accept_server(t_server *s, char **argv)
{
  (void)argv;
  s->addrlen = sizeof(s->clientaddr);
  if ((s->newfd = accept(s->listener, (struct sockaddr *)&(s->clientaddr),
			 (socklen_t*)&(s->addrlen))) == -1)
      perror("Server-accept() error !");
  else
    {
      printf("Server-accept() is OK...\n");
      FD_SET(s->newfd, &(s->master));
      if (s->newfd > s->fdmax)
	{
	  s->fdmax = s->newfd;
	  g_fdmax = s->fdmax;
	}
      create_client(s, s->newfd,
		    "default_team_name", s->map->size);
      printf("New connection from %s on socket %d\n",
	     inet_ntoa(s->clientaddr.sin_addr), s->newfd);
      protocole_connexion(s, s->newfd);
    }
}

void		read_write_server(t_server *s, int i, char **argv)
{
  ssize_t	nbytes;
  char		*tmp;
  t_client	*c;

  c = get_client_by_id(s->clients, i);
  tmp = xmalloc(4096 * sizeof(char));
  memset(tmp, '\0', 4096);
  if ((nbytes = read(i, tmp, 4096)) <= 0)
    {
      if (nbytes == 0)
	printf("%s: socket %d hung up\n", argv[0], i);
      else
	perror("read() error!");
      ring_buffer_destroy(c->buffer);
      close(i);
      FD_CLR(i, &(s->master));
    }
  else
    {
      ring_buffer_write(c->buffer, tmp, strlen(tmp));
      s->i = i;
      prepare_for_exec(s, c);
      check_exec(s);
    }
  free(tmp);
  /* free(c->team_name); */
  /* free(c->pos); */
  /* free_list(c->inventory); */
  /* free_list(c->cmds); */
  /* free(c->buffer->buffer); */
  /* free(c->buffer); */
  /* free(c); */
}
