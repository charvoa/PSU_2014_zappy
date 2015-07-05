/*
** cmd.h for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sun Jul  5 15:16:42 2015 Serge Heitzler
** Last update Sun Jul  5 15:17:21 2015 Serge Heitzler
*/

#ifndef		        CMD_H_
# define		CMD_H_

typedef struct		s_cmd
{
  char		       	*label;
  long			delay;
  struct timespec       exec_at;
  int		        opt;
}			t_cmd;

#endif /* CMD_H_ */
