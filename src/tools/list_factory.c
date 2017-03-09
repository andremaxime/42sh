/*
** list.c for list.c in /home/vatout_a/rendu/PSU_2015_minishell2
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Tue Mar 29 17:20:57 2016 Vatoutine
** Last update Sun Jun  5 23:29:27 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

int		my_list_print(t_list *env)
{
  t_funk	*funk;

  funk = env->first;
  while (funk != NULL)
    {
      my_putstr(funk->line);
      my_putchar('\n');
      funk = funk->next;
    }
  return (0);
}

int		get_env(t_list *env, char *src)
{
  src = src;
  my_list_print(env);
  return (0);
}
