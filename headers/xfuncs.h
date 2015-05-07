/*
** xfuncs.h for zappy in /home/heitzl_s/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Wed May  6 13:49:05 2015 Serge Heitzler
** Last update Thu May  7 11:57:49 2015 Serge Heitzler
*/

#ifndef			XFUNCS_H_
# define		XFUNCS_H_

/* xmalloc.c */
void			*xmalloc(size_t);

/* xbind.c */
void			*xbind(int);

/* xlisten.c */
void			*xlisten(int, int);

/* xsocket.c */
void			*xsocket(int);

#endif			/* !XFUNCS_H_ */
