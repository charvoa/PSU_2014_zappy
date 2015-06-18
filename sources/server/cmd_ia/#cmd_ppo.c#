#include "server.h"

int		cmd_ppo(t_server *s, t_client *c, const char *cmd)
{
  int		*id_targeted;
  char		*final;
  t_client	*target;

  id_targeted = xmalloc(sizeof(int));
  sscanf(cmd, "ppo #%d", id_targeted);
  target = get_client_by_id(s->clients, *id_targeted);
  final = xmalloc(sizeof(char) * (9 + int_size_to_malloc(target->fd)
				  + int_size_to_malloc((int)target->pos->x)
				  + int_size_to_malloc((int)target->pos->y)
				  + int_size_to_malloc(target->orientation)));
  memset(final, 0, (9 + int_size_to_malloc(target->fd)
		    + int_size_to_malloc((int)target->pos->x)
		    + int_size_to_malloc((int)target->pos->y)
		    + int_size_to_malloc(target->orientation)));
  sprintf(final, "ppo #%d %d %d %d\n", target->fd,
	  target->pos->x, target->pos->y, target->orientation);
  send_data(c->fd, final);
  return (SUCCESS);
}
