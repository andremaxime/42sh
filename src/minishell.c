/*
** minishell.c for minishell.c in /home/vatout_a/rendu/PSU_2015_minishell2
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Wed Mar 23 16:26:23 2016 Vatoutine
** Last update Sun Jun  5 23:13:09 2016 RIMBAUD
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "struct.h"
#include "get_next_line.h"

int		my_algo_2(t_list *env, char *src)
{
  char		**tmp;
  int		inc;

  inc = 0;
  tmp = NULL;
  if ((tmp = my_str_to_wordtab(tmp, src, ';')) == NULL)
    return (1);
  while (tmp[inc] != NULL)
    {
      tmp[inc] = my_epur_str(tmp[inc]);
      my_parse_src(env, tmp[inc]);
      inc++;
    }
  my_tab_free(tmp);
  return (1);
}

int		my_algo(t_list *env)
{
  char		*src;

  init_env(env);
  while (42)
    {
      if ((src = display_prompt(src)) != NULL)
	{
	  if (my_quote_check(src) != -1)
	    my_algo_2(env, src);
	  free(src);
	}
    }
  return (0);
}

int		minishell(char **envp)
{
  t_list	*env;
  int		res;

  env = NULL;
  env = my_env_to_list(env, envp);
  res = -2;
  res = my_algo(env);
  if (env == NULL)
    return (res);
  else
    my_free_list(env);
  return (res);
}
