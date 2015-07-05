/*
** xfuncs.h for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May  6 13:49:05 2015 Serge Heitzler
** Last update Sun Jul  5 19:10:17 2015 Serge Heitzler
*/

#ifndef			XFUNCS_H_
# define		XFUNCS_H_

# include <sys/socket.h>

/* xmalloc.c */
void			*xmalloc(size_t);

/* xbind.c */
int			xbind(int, const struct sockaddr *, socklen_t);

/* xlisten.c */
int			xlisten(int, int);

/* xsocket.c */
int			xsocket(int, int, int);

#endif			/* !XFUNCS_H_ */
