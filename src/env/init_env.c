/*
** init_env.c for  in /home/andre_c/systemeunix/PSU_2015_42sh/minishell2/env
**
** Made by andre
** Login   <andre_c@epitech.net>
**
** Started on  Fri Jun  3 21:32:22 2016 andre
** Last update Sun Jun  5 23:05:35 2016 RIMBAUD
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

int		init_pwd(t_list *env)
{
  char		pwd[4096];
  char		*nouv;
  int		i;
  int		z;

  i = 0;
  getcwd(pwd, 4096);
  if ((nouv = malloc(sizeof(char) * (my_strlen(pwd) + 12))) == NULL)
    return (1);
  my_memset(nouv, my_strlen(pwd));
  nouv = my_strcpy(nouv, "setenv PWD ");
  z = my_strlen(nouv);
  while (pwd[i] != '\0')
    nouv[z++] = pwd[i++];
  nouv[z] = '\0';
  go_env(env, nouv);
  free(nouv);
  return (0);
}

int		init_env(t_list *env)
{
  init_pwd(env);
  return (0);
}
