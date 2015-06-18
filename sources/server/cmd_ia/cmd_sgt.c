#include "server.h"

int		cmd_sgt(t_server *s, t_client *c, const char *cmd)
{
  (void)cmd;
  char		*final;

  final = xmalloc(sizeof(char) *
		  (5 + int_size_to_malloc(s->time_action)));
  memset(final, 0, 5 + int_size_to_malloc(s->time_action));
  sprintf(final, "sgt %d\n", s->time_action);
  send_data(c->fd, final);
  return (SUCCESS);
}
