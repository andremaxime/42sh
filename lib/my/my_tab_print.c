/*
** my_tab_print.c for my_tab_print.c in /rendu/PSU_2015_minishell2/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Thu Mar 24 09:58:39 2016 Vatoutine
** Last update Sun Jun  5 22:21:23 2016 Maisonnave Florian
*/

#include <stdlib.h>
#include "my.h"

int		my_tab_print(char **tab)
{
  int		inc;

  inc = 0;
  while (tab[inc] != NULL)
    {
      if ((my_putstr(tab[inc])) == -1)
	return (-1);
      my_putchar('\n');
      inc++;
    }
  return (0);
}
