#include "server.h"

int		cmd_sst(t_server *s, t_client *c, const char *cmd)
{
  char		*final;
  char		value[6];

  memset(value, 0, 6);
  sscanf(cmd, "sst %s", value);
  s->time_action = atoi(value);
  final = xmalloc(sizeof(char) *
		  (5 + strlen(value)));
  memset(final, 0, 5 + strlen(value));
  sprintf(final, "sgt %s\n", value);
  send_data(c->fd, final);
  return (SUCCESS);
}
