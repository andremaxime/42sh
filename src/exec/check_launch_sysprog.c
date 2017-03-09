/*
** check_launch_sysprog.c for check_launch_sysprog.c in /PSU_2015_minishell2
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Fri Mar 25 16:02:39 2016 Vatoutine
** Last update Sun Jun  5 23:10:21 2016 RIMBAUD
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int		check_prog_or_user(char **command, char **tmp)
{
  int		res;
  char		*user;
  int		ac;

  user = "./";
  res = 0;
  if ((res = my_compare(command[0], user)) == 0 || command[0][0] == '/')
    {
      if (access(command[0], F_OK | X_OK) == 0)
	return (-1);
      else
	error_sys(1, command[0]);
    }
  else if (res != 1)
    {
      if ((ac = my_check_access(tmp)) >= 0)
	return (ac);
      else
	error_sys(2, command[0]);
    }
  return (-2);
}

int		check_launch_sysprog(char **path, t_list *env, char *src)
{
  char		**command;
  char		**tmp;
  char		**envp;
  int		ac;

  command = NULL;
  tmp = NULL;
  envp = NULL;
  if ((envp = my_list_to_tab(envp, env)) == NULL ||
      (command = my_str_to_wordtab(command, src, 32)) == NULL ||
      (tmp = check_exec(path, command)) == NULL)
    return (error_sys(2, src));
  if ((ac = check_prog_or_user(command, tmp)) == -1)
    my_aout_exec(command, envp);
  else if (ac >= 0)
    my_exec(tmp, command, envp, ac);
  free(envp);
  my_tab_free(tmp);
  my_tab_free(command);
  return (0);
}
