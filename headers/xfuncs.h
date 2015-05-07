/*
** xfuncs.h for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May  6 13:49:05 2015 Serge Heitzler
** Last update Thu May  7 14:19:44 2015 Audibert Louis
*/

#ifndef			XFUNCS_H_
# define		XFUNCS_H_

/* xmalloc.c */
void			*xmalloc(size_t);

/* xbind.c */
int			xbind(int);

/* xlisten.c */
int			xlisten(int, int);

/* xsocket.c */
int			xsocket(int);

#endif			/* !XFUNCS_H_ */
