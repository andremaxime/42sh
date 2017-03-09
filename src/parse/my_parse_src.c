/*
** my_parse_src.c for my_parse_src.c in /rendu/PSU_2015_minishell2/parse
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Wed Apr  6 15:04:43 2016 Vatoutine
** Last update Sun Jun  5 23:38:32 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"

int		launch_exec_prelli(t_list *env, char *src)
{
  char		**path;

  path = NULL;
  if (src[0] == '\0' || src[0] == '\t')
    return (0);
  if ((path = my_parse(path, env, "PATH=")) == NULL)
    return (error_sys(2, src));
  check_launch_sysprog(path, env, src);
  my_tab_free(path);
  return (0);
}

int		my_fill_default(char *tab[7])
{
  tab[0] = "cd";
  tab[1] = "env";
  tab[2] = "setenv";
  tab[3] = "unsetenv";
  tab[4] = "exit";
  tab[5] = "echo";
  tab[6] = "pwd";
  return (0);
}

int		my_init_tabfonct(int (*tab_fonct[7])(t_list *, char *))
{
  tab_fonct[0] = get_cd;
  tab_fonct[1] = get_env;
  tab_fonct[2] = go_env;
  tab_fonct[3] = unset_env;
  tab_fonct[4] = get_exit;
  tab_fonct[5] = get_echo;
  tab_fonct[6] = get_pwd;
  return (0);
}

int		check_pipe(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '|')
	return (0);
      i++;
    }
  return (1);
}

int		my_parse_src(t_list *env, char *src)
{
  int		i;
  char		*default_command[7];
  int		(*tab_fonct[7])(t_list *, char *);

  i = 0;
  my_fill_default(default_command);
  my_init_tabfonct(tab_fonct);
  while (i < 7)
    {
      if (my_compare(src, default_command[i]) == 0)
	{
	  tab_fonct[i](env, src);
	  return (0);
	}
      i++;
    }
  if (env != NULL)
    {
      if (check_redir_op(src) == 0)
      	check_tab(src, env);
      else if (check_pipe(src) == 0)
	multi_pipe(init_triple(src), env);
      else
	launch_exec_prelli(env, src);
    }
  return (0);
}
