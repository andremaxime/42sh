/*
** doubleet.c for double et && in /home/darrig_s/PROJETS/SYSTEME_UNIX/PSU_2015_42sh/test/redir
** 
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
** 
** Started on  Sat Jun  4 22:35:50 2016 Sophie Darrigol
** Last update Sun Jun  5 23:40:49 2016 RIMBAUD
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"
#include "pipe.h"

int		part_two(char **args, char **env, char **path)
{
  int		pid;
  int		statut;
  char		*pathname;

  if ((pathname = access_pipe(path, args[0])) == NULL)
    {
      my_putstr_error(args[0]);
      my_putstr_error(" : command not found\n");
      return (-1);
    }
  pid = fork();
  if (pid == 0)
    {
      if (access(pathname, F_OK | X_OK) != 0 ||
	  execve(pathname, args, env) == -1)
	{
	  my_putstr_error(args[0]);
	  my_putstr_error(" : command not found\n");
	  return (-1);
	}
    }
  else if (pid == -1)
    return (-1);
  wait(&statut);
  return (statut);
}

int		doubleet(t_list *list, char **to_exec)
{
  char		**path;
  char		**env;
  char		**right_args;
  char		**left_args;

  left_args = my_str_to_worktab(to_exec[0], 0, 0);
  right_args = my_str_to_worktab(to_exec[1], 0, 0);
  env = NULL;
  if ((env = my_list_to_tab(env, list)) == NULL)
    return (-1);
  if ((path = create_path(env)) == NULL)
    return (-1);
  if (part_two(left_args, env, path) != 0)
    return (-1);
  if (part_two(right_args, env, path) != 0)
    return (-1);
  return (0);
}
