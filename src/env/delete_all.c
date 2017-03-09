/*
** delete_all.c for  in /home/andre_c/systemeunix/PSU_2015_42sh/minishell2/env
**
** Made by andre
** Login   <andre_c@epitech.net>
**
** Started on  Thu Jun  2 15:06:03 2016 andre
** Last update Sun Jun  5 23:04:41 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"

void		delete_all(t_list *env)
{
  t_funk	*elem;

  if ((elem = malloc(sizeof(t_funk *))) == NULL)
    exit(EXIT_FAILURE);
  elem = env->first;
  while (env->length != 0)
    {
      delete_elem(env, elem);
      elem = elem->next;
    }
  if (elem != NULL)
    free(elem);
}
