/*
** parser.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/server_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Mar 10 15:05:32 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:48:47 2015 Nicolas Charvoz
*/

#include "client.h"

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

void	parser(char *str, t_client *c)
{
  int   i;
  int   b;
  int   a;

  b = 0;
  i = 0;
  a = 0;
  c->args = xmalloc((count_word2(str) + 1) * sizeof(char*));
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n')
        while (str[i] == ' ')
          i++;
      if (str[i] != '\0')
        {
          c->args[a] = xmalloc(((countchar2(str + i) + 1)) * sizeof(char));
          c->args[a] = memset(c->args[a], 0, ((countchar2(str + i) + 1)));
          while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
            c->args[a][b++] = str[i++];
          c->args[a][b] = '\0';
          a = a + 1;
          b = 0;
        }
    }
  c->args[a] = NULL;
}
