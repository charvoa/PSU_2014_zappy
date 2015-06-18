#include "server.h"

char		*build_string_to_send(t_client *c)
{
  char		*final;

  // malloc final en fonction du nom des objets et de la quantité
  final = xmalloc(sizeof(char) * (7 + int_size_to_malloc(c->fd)
				  + int_size_to_malloc((int)c->level)));
  memset(final, 0, (7 + int_size_to_malloc(c->fd)
		    + int_size_to_malloc((int)c->level)));
  sprintf(final, "pin #%d %d\n", c->fd, c->level);
  return (final);
}

int		cmd_pin(t_server *s, t_client *c, const char *cmd)
{
  int		*id_targeted;
  t_client	*target;

  id_targeted = xmalloc(sizeof(int));
  sscanf(cmd, "pin #%d", id_targeted);
  target = get_client_by_id(s->clients, *id_targeted);
  send_data(c->fd, build_string_to_send(target));
  return (SUCCESS);
}
