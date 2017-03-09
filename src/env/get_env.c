/*
** get_env.c for get_env.c in /home/vatout_a/rendu/PSU_2015_minishell2/env
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Fri Apr  1 16:28:11 2016 Vatoutine
** Last update Sun Jun  5 23:05:04 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"

char		**my_list_to_tab(char **envp, t_list *env)
{
  int		inc;
  t_funk	*funk;

  inc = 0;
  funk = env->first;
  if ((envp = malloc(sizeof(char *) * (env->length + 1))) == NULL)
    return (NULL);
  envp[env->length] = NULL;
  while (funk != NULL)
    {
      envp[inc] = funk->line;
      inc++;
      funk = funk->next;
    }
  return (envp);
}

t_list		*my_env_to_list(t_list *env, char **envp)
{
  int		inc;

  inc = 0;
  if (envp == NULL)
    my_putchar('c');
  env = my_init_list(env);
  while (envp[inc] != NULL)
    {
      env = add_elem(env, envp[inc]);
      inc++;
    }
  return (env);
}
