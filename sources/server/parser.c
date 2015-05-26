/*
** parser.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/server_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Mar 10 15:05:32 2015 Nicolas Charvoz
** Last update Mon May 25 16:39:48 2015 Nicolas Charvoz
*/

#include "server.h"

int     countchar2(char *str)
{
  int   c;

  c = 0;
  while ((str[c] != ' ') && (str[c] != '\0') && (str[c] != '\n'))
    c++;
  c++;
  return (c);
}

int     count_word2(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 1;
  while ((str[i] != '\0') && (str[i] != '\n'))
    {
      if (str[i] == ' ' && str[i + 1] != '\0')
        n++;
      i++;
    }
  return (n);
}

void	parser(t_server *s, char *str)
{
   int   i;
   int   b;
   int   a;

   b = 0;
   i = 0;
   a = 0;
   s->tab = xmalloc((count_word2(str) + 1) * sizeof(char*));
   while (str[i] != '\n' && str[i] != '\0')
     {
       if (str[i] == ' ' || str[i] == '\n')
	 while (str[i] == ' ')
	   i++;
       if (str[i] != '\0')
	 {
	   s->tab[a] = xmalloc(((countchar2(str + i) + 1)) * sizeof(char));
	   s->tab[a] = memset(s->tab[a], 0, ((countchar2(str + i) + 1)));
	   while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
	     s->tab[a][b++] = str[i++];
	   s->tab[a][b] = '\0';
	   a = a + 1;
	   b = 0;
	 }
     }
   s->tab[a] = NULL;
}
