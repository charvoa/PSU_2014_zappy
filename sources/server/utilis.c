/*
** utilis.c for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:38:51 2015 Nicolas Charvoz
** Last update Mon May  4 23:47:14 2015 Nicolas Charvoz
*/

#include "server.h"

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

void	accept_server(t_server *s, char **argv)
{
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
	printf("%s: New connection from %s on socket %d\n", argv[0],
	     inet_ntoa(s->clientaddr.sin_addr), s->newfd);
    }
}

void		read_write_server(t_server *s, int i, char **argv)
{
  ssize_t	nbytes;

  s->buf = xmalloc(4096 * sizeof(char));
  memset(s->buf, '\0', 4096);
  if ((nbytes = read(i, s->buf, 4095)) <= 0)
    {
      if (nbytes == 0)
	printf("%s: socket %d hung up\n", argv[0], i);
      else
	perror("read() error!");
      close(i);
      FD_CLR(i, &(s->master));
    }
  else
    {
      s->i = i;
      char buf[4096];
      bzero(buf, 4096);
      sprintf(buf, "I read : %s\n", s->buf);
      write(s->i, buf, strlen(buf));
      //exec_cmd(s);
    }
  free(s->buf);
}
