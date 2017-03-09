/*
** test_home.c for  in /home/andre_c/systemeunix/PSU_2015_42sh/minishell2/cd
**
** Made by andre
** Login   <andre_c@epitech.net>
**
** Started on  Fri Jun  3 20:31:48 2016 andre
** Last update Sun Jun  5 23:26:46 2016 RIMBAUD
*/

#include "my.h"

int		test_home_cd(char *home)
{
  if (my_strcmp(".", home) == 0)
    my_putstr("cd: No home directory.\n");
  return (0);
}

int		test_home(char *home)
{
  if (my_strcmp(".", home) == 0)
    my_putstr("No $home variable set.\n");
  return (0);
}
