/*
** server.h for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:19:26 2015 Nicolas Charvoz
** Last update Thu May  7 10:41:17 2015 Audibert Louis
*/

#ifndef			SERVER_H_
# define		SERVER_H_

# include		<stdio.h>
# include		<stdlib.h>
# include		<string.h>
# include		<unistd.h>
# include		<sys/types.h>
# include		<sys/socket.h>
# include		<sys/select.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<sys/stat.h>
# include		<fcntl.h>
# include		<limits.h>
# include		<signal.h>

# define		KNRM	"\x1B[0m"
# define		KRED	"\x1B[31m"
# define		KGRN	"\x1B[32m"
# define		KYEL	"\x1B[33m"
# define		KBLU	"\x1B[34m"
# define		KMAG	"\x1B[35m"
# define		KCYN	"\x1B[36m"
# define		KWHT	"\x1B[37m"
# define		RESET	"\033[0m"

# define		SIZE_OF_TAB	15
# define		c120	"120: Service ready in %s minutes.\n".
# define		c125	"125: Data connection already open; transfer starting.\n"
# define		c150	"150: File status okay; about to open data connection.\n"
# define		c200	"200: Command okay.\n"
# define		c202	"202: Command not implemented.\n"
# define		c214	"214: %s\n"
# define		c220	"220: Service ready for new user.\n"
# define		c221	"221: Service closing control connection.\n"
# define		c226	"226: Closing data connection.\n"
# define		c230	"230: User logged in, proceed.\n"
# define		c250	"250: Requested file action okay, completed.\n"
# define		c257	"257: %s created.\n"
# define		c331	"331: User name okay, need password.\n"
# define		c332	"332: Need account for login.\n"
# define		c500	"500 OOPS: "
# define		c530	"530: Not logged in (Please login using 'user')"

typedef struct		s_serv_info
{
  struct protoent	*proto;
  struct sockaddr_in	s_in;
  int			socket;
}			t_serv_info;

typedef struct s_server
{
  unsigned int	port; // -p
  unsigned int	Xmap; // -x
  unsigned int	Ymap; // -y
  char		*team_names; // -n
  unsigned int	nb_max_clients_by_team; // -c
  unsigned int	time_action; // -t
  int		fdmax;
  int		graph_launched;
  t_serv_info	serv_info;
  fd_set	read_fds;
  fd_set	master;
  //charvo_a struct
  struct sockaddr_in	serveraddr;
  struct sockaddr_in	clientaddr;
  int			listener;
  int			newfd;
  char			*buf;
  int			addrlen;
  char			**args;
  int			i;
  //end
  // List de client
}		t_server;


extern	int		g_verbose;
extern	int		g_listener;
extern	int		g_fdmax;

int			xsocket(int, int, int);
void			xbind(int, const struct sockaddr*, socklen_t);
void			xlisten(int, int);
void			init_socket(t_server*);
void			bind_socket(t_server*, int);
void			accept_server(t_server*, char**);
void			read_write_server(t_server*, int, char**);
void			parser(t_server*, char *);
void			exec_cmd(t_server*);
int			user_server(t_server*);
int			ls_server(t_server*);
int			lls_server(t_server*);
int			cd_server(t_server*);
int			lcd_server(t_server*);
int			get_server(t_server*);
int			put_server(t_server*);
int			pwd_server(t_server*);
int			lpwd_server(t_server*);
int			clear_client(t_server*);
int			noopuser_client(t_server*);
int			quit_server(t_server*);
int			noop_server(t_server*);
char			*read_file(char*);
int			my_cd(char*, t_server*);
void			read_inf(int, int, FILE*);
char			*base64encode(const void *, int);
char			*base64decode(const void*, int);
void			*xmalloc(int);
void			my_printf(const char *, ...);
void			write_to_client(t_server *, char *);

#endif			/* !SERVER_H_ */