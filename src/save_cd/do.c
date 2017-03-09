/*
** do.c for  in /home/andre/systemeunix/PSU_2015_minishell2
**
** Made by andre
** Login   <andre@epitech.net>
**
** Started on  Sun Apr 10 20:29:22 2016 andre
** Last update Sun Jun  5 23:21:18 2016 RIMBAUD
*/

#include <unistd.h>
#include "my.h"

int		do_cd3(char *home, char **tmp, char *old)
{
  home = home;
  if (my_strcmp(tmp[1], "-") == 0)
    {
      if (chdir(old) == -1)
	return (0);
      return (1);
    }
  if (check_debut("/", tmp[1]) == 0)
    {
      if (chdir(tmp[1]) == -1)
	return (0);
      return (1);
    }
  return (0);
}
