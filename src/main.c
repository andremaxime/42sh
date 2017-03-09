/*
** main.c for main.c in /home/vatout_a/epitech/USP/minishell
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Mon Jan 18 15:40:45 2016 Vatoutine
** Last update	Wed Apr 06 11:56:25 2016 Vatoutine Artem
*/

#include <stdlib.h>
#include "my.h"

int		main(int ac, char **av, char **envp)
{
  int		res;

  if (ac > 1 || av[1] != NULL)
    {
      my_putstr_error("Usage: ");
      my_putstr_error(av[0]);
      my_putstr_error(".\n");
      return (1);
    }
  res = minishell(envp);
  return (res);
}
