/*
** pipe.h for  in /home/maison_f/Epitech/rendu/PSU_2015_42sh/minishell2/pipe
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sat Jun  4 03:41:13 2016 Maisonnave Florian
** Last update Sun Jun  5 23:32:36 2016 RIMBAUD
*/

#ifndef PIPE_H_
# define PIPE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

typedef struct	s_pipe
{
  char		*way;
  int		pipefd[2];
  pid_t		pid;
  int		fd;
  int		state;
}		t_pipe;

int		use_pipe();
char		*exec_pipe(t_pipe*, char***, char**, char**);
char		*exec_pipe_end(char*, char***, int*, char**);
char		*access_pipe(char**, char*);
char		*my_access_strcat(char*, char*);
char		**create_path(char**);
char		*find_path(char**);
char		*save_path(char**, int);
char		*get_next_line(const int);
char		*error_pipe(t_pipe*, char***);

#endif /* PIPE_H_ */
