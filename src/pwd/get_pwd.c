/*
** get_pwd.c for  in /home/andre_c/systemeunix/PSU_2015_42sh/minishell2/pwd
**
** Made by andre
** Login   <andre_c@epitech.net>
**
** Started on  Fri Jun  3 16:11:49 2016 andre
** Last update Sun Jun  5 23:21:00 2016 RIMBAUD
*/

#include <unistd.h>
#include "my.h"

int		get_pwd(t_list *env, char *src)
{
  char		str[4096];

  env = env;
  if (my_strcmp(src, "pwd") != 0)
    my_putstr("pwd: ignores arguments.\n");
  getcwd(str, 4096);
  my_putstr(str);
  my_putchar('\n');
  return (0);
}
