#include "server.h"

int		size_of_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}
