#include "server.h"

int		cmd_plv(t_server *s, t_client *c, const char *cmd)
{
  int		*id_targeted;
  char		*final;
  t_client	*target;

  id_targeted = xmalloc(sizeof(int));
  sscanf(cmd, "plv #%d", id_targeted);
  target = get_client_by_id(s->clients, *id_targeted);
  final = xmalloc(sizeof(char) * (7 + int_size_to_malloc(target->fd)
				  + int_size_to_malloc((int)target->level)));
  memset(final, 0, (7 + int_size_to_malloc(target->fd)
		    + int_size_to_malloc((int)target->level)));
  sprintf(final, "plv #%d %d\n", target->fd, target->level);
  send_data(c->fd, final);
  return (SUCCESS);
}
