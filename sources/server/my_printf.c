/*
** my_printf.c for zappy in /home/nicolas/verbose
**
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
**
** Started on  Tue May  5 14:41:57 2015 Nicolas Girardot
** Last update Wed Jul  1 11:11:23 2015 Serge Heitzler
*/

#include <stdarg.h>
#include <stdio.h>
#include "functions.h"

void	my_printf(char *format, ...)
{
  va_list args;

  if (g_verbose == 1)
    {
      va_start(args, format);
      vprintf(format, args);
      va_end(args);
    }
}
