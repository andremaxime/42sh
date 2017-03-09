/*
** my_tab_free.c for my_tab_free.c in /vatout_a/rendu/PSU_2015_minishell2/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Thu Mar 24 09:56:40 2016 Vatoutine
** Last update Sun Jun  5 22:21:07 2016 Maisonnave Florian
*/

#include <stdlib.h>
#include "my.h"

int	my_tab_free(char **tab)
{
  int	inc;

  inc = 0;
  while (tab[inc] != NULL)
    {
      free(tab[inc]);
      inc++;
    }
  free(tab);
  return (0);
}
