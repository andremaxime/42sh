/*
** my_compare.c for my_compare.c in /PSU_2015_minishell2/tools
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Fri Apr  1 15:45:03 2016 Vatoutine
** Last update Sun Jun  5 23:29:53 2016 RIMBAUD
*/

#include "my.h"

int		check_letter(char *src)
{
  int		inc;
  int		res;

  inc = 0;
  res = 0;
  if (src[0] == '\0')
    return (0);
  while (src[inc] != '\0')
    {
      if (src[inc] == '-')
        res++;
      else if ((src[inc] > 57) || (src[inc] < 48))
        {
          my_putstr("exit: Badly formed number.\n");
          return (-1);
        }
      inc++;
    }
  if (res >= 2)
    {
      my_putstr("exit: Badly formed number.\n");
      return (-1);
    }
  return (0);
}

int		my_compare(char *src, char *dest)
{
  int		inc;

  inc = 0;
  while (dest[inc] != '\0')
    {
      if (dest[inc] != src[inc])
	return (-1);
      inc++;
    }
  return (0);
}
