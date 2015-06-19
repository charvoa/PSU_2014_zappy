#include "server.h"

char		*get_objects_from_inventory(t_list *inventory)
{
  int		nbr[7];
  int		size_malloc;
  char		*res;

  nbr[0] = get_nbr_of(FOOD, inventory);
  nbr[1] = get_nbr_of_rock(LIMEMATE, inventory);
  nbr[2] = get_nbr_of_rock(DERAUMERE, inventory);
  nbr[3] = get_nbr_of_rock(SIBUR, inventory);
  nbr[4] = get_nbr_of_rock(MENDIANE, inventory);
  nbr[5] = get_nbr_of_rock(PHIRAS, inventory);
  nbr[6] = get_nbr_of_rock(THYSTAME, inventory);
  size_malloc = (77 + int_size_to_malloc(nbr[0])
		 + int_size_to_malloc(nbr[1])  + int_size_to_malloc(nbr[2])
		 + int_size_to_malloc(nbr[3])  + int_size_to_malloc(nbr[4])
		 + int_size_to_malloc(nbr[5])  + int_size_to_malloc(nbr[6]));
  res = xmalloc(sizeof(char) * size_malloc);
  memset(res, 0, size_malloc);
  // ! Trop de colonnes !
  sprintf(res, "{nourriture %d, limemate %d, deraumere %d, sibur %d, mendiane %d, phiras, %d, thystame %d}\n", nbr[0], nbr[1], nbr[2], nbr[3], nbr[4], nbr[5], nbr[6]);
  return (res);
}

int		cmd_inventory(t_server *s, t_client *c, const char *cmd)
{
  (void)cmd;
  (void)s;
  char		*final;

  final = get_objects_from_inventory(c->inventory);
  send_data(c->fd, final);
  return (SUCCESS);
}
