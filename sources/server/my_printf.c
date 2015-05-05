/*
** my_printf.c for zappy in /home/nicolas/verbose
** 
** Made by Nicolas Girardot
** Login   <girard_s@epitech.net>
** 
** Started on  Tue May  5 14:41:57 2015 Nicolas Girardot
** Last update Tue May  5 15:30:32 2015 Nicolas Girardot
*/

#include <stdarg.h>
#include <stdio.h>
#include "server.h"

void	my_printf(const char *format, ...)
{
  va_list args;
  
  if (g_verbose == 1)
    {
      va_start(args, format);
      vprintf(format, args);
      va_end(args);
    }
}
