/*
** xfuncs.h for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May  6 13:49:05 2015 Serge Heitzler
** Last update Thu May  7 14:31:03 2015 Serge Heitzler
*/

#ifndef			XFUNCS_H_
# define		XFUNCS_H_

/* xmalloc.c */
void			*xmalloc(size_t);

/* xbind.c */
int			xbind(int, const struct sockaddr *, socklen_t);

/* xlisten.c */
int			xlisten(int, int);

/* xsocket.c */
int			xsocket(int, int, int);

#endif			/* !XFUNCS_H_ */
