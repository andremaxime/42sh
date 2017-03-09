/*
** get_echo.c for  in /home/andre_c/systemeunix/PSU_2015_42sh/minishell2/echo
**
** Made by andre
** Login   <andre_c@epitech.net>
**
** Started on  Thu Jun  2 21:17:25 2016 andre
** Last update Sun Jun  5 23:03:15 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

int		get_echoownflags(char *src, char **tab)
{
  int		i;

  i = 0;
  my_tab_free(tab);
  while (src[i] != ' ' && src[i] != '\0')
    i++;
  if (src[i] == '\0')
    {
      my_putchar('\n');
      return (0);
    }
  i++;
  while (src[i] != '\0')
    my_putchar(src[i++]);
  my_putchar('\n');
  return (0);
}

int		check_flag(char *tabz, char *flags[1])
{
  int		i;

  i = 0;
  while (i < 1)
    {
      if (my_strcmp(tabz, flags[i]) == 0)
	return (i);
      i++;
    }
  return (-1);
}

int		get_echo(t_list *env, char *src)
{
  int		i;
  char		*flags[1];
  int		(*tab_flags[1])(char *src);
  char		**tab;
  int		z;

  z = 0;
  env = env;
  tab = NULL;
  tab = my_str_to_wordtab(tab, src, ' ');
  init_echoflags(flags);
  init_echotab(tab_flags);
  i = 0;
  while (tab[z] != NULL)
    {
      if ((i = check_flag(tab[z], flags)) != -1 && z == 1)
	{
	  tab_flags[i](src);
	  my_tab_free(tab);
	  return (0);
	}
      z++;
    }
  get_echoownflags(src, tab);
  return (0);
}
