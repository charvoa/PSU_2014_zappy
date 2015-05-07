/*
** my_str_to_wordtab.c for myftp in /home/audibe_l/rendu/PSU_2014_myftp/Server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Wed Mar 11 13:37:48 2015 Audibert Louis
** Last update Sun Mar 22 18:19:12 2015 Audibert Louis
*/

#include "server.h"

int     my_count_word(char *s)
{
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  while (s[i])
    {
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
          || (s[i] >= '0' && s[i] <= '9'))
        {
          cpt = cpt + 1;
          while (s[i] && ((s[i] >= 'a' && s[i] <= 'z')
                          || (s[i] >= 'A' && s[i] <= 'Z')
                          || (s[i] >= '0' && s[i] <= '9')))
            i = i + 1;
        }
      i = i + 1;
    }
  return (cpt);
}

int     my_count_char(char *s, int *i)
{
  int   cpt;

  cpt = 0;
  while (s[*i] && ((s[*i] >= 'a' && s[*i] <= 'z')
		   || (s[*i] >= 'A' && s[*i] <= 'Z')
		   || (s[*i] >= '0' && s[*i] <= '9')))
    {
      cpt = cpt + 1;
      *i = *i + 1;
    }
  return (cpt);
}

char    **my_str_to_wordtab(char *str)
{
  int   i;
  int   n;
  int   word;
  char  **tab;

  i = 0;
  n = 0;
  word = 0;
  word = my_count_word(str);
  if ((tab = (char **)malloc(sizeof(char *) * word)) == NULL)
    show_error("Malloc error.");
  while (str[i] && word > 0)
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
          || (str[i] >= '0' && str[i] <= '9'))
        {
          tab[n] = strdup(str + i);
          tab[n][my_count_char(str, &i)] = '\0';
          n = n + 1;
          word = word - 1;
        }
      i = i + 1;
    }
  tab[my_count_word(str)] = NULL;
  return (tab);
}
