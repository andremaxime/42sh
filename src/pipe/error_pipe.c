/*
** error_pipe.c for  in /home/maison_f/Epitech/rendu/PSU_2015_42sh/minishell2/pipe
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sun Jun  5 06:02:47 2016 Maisonnave Florian
** Last update Sun Jun  5 23:16:48 2016 RIMBAUD
*/

#include "pipe.h"
#include "struct.h"
#include "my.h"

char		*error_pipe(t_pipe *p, char ***cmd)
{
  close(p->pipefd[1]);
  write(2, *cmd[0], my_strlen(*cmd[0]));
  write(2, ": Command not found.\n", 21);
  exit(EXIT_SUCCESS);
  return (*cmd[0]);
}
