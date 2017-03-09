/*
** echo_tab.c for  in /home/andre_c/systemeunix/PSU_2015_42sh/minishell2/echo
**
** Made by andre
** Login   <andre_c@epitech.net>
**
** Started on  Fri Jun  3 15:36:50 2016 andre
** Last update Sun Jun  5 23:02:17 2016 RIMBAUD
*/

#include "my.h"

int		get_n(char *src)
{
  int		i;

  i = 0;
  while (src[i] != '-' && src[i + 1] != 'n')
    i++;
  i++;
  if (src[i] == '\0')
    return (0);
  i++;
  if (src[i] == '\0')
    return (0);
  i++;
  while (src[i] != '\0')
    my_putchar(src[i++]);
  return (0);
}

void		init_echoflags(char *flags[1])
{
  flags[0] = "-n";
}

void		init_echotab(int (*tab_flags[1])(char *src))
{
  tab_flags[0] = get_n;
}
