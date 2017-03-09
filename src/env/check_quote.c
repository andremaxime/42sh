/*
** check_quote.c for check_quote.c in rendu/PSU_2015_42sh/minishell2/env
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Sun Jun  5 04:30:32 2016 Vatoutine
** Last update Sun Jun  5 23:04:21 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"

static int	print_unmatched(char z)
{
  my_putstr("Unmatched ");
  my_putchar(z);
  my_putstr(".\n");
  return (-1);
}

static int	fill_unmatched(char *src)
{
  src[0] = 34;
  src[1] = 39;
  src[2] = 96;
  src[3] = 0;
  return (0);
}

int		my_quote_check(char *src)
{
  int		inc;
  int		i;
  int		res;
  char		check[4];

  inc = 0;
  i = 0;
  res = 0;
  fill_unmatched(check);
  while (inc < 4)
    {
      while (src[i] != '\0')
	{
	  if (src[i] == check[inc])
	    res++;
	  i++;
	}
      if (res == 1)
	return (print_unmatched(check[inc]));
      i = 0;
      res = 0;
      inc++;
    }
  return (0);
}

char		*remove_quotes(char *src)
{
  int		inc;
  int		i;
  char		check[3];
  char		*tmp;

  check[0] = '"';
  check[1] = '\'';
  check[2] = '`';
  inc = 0;
  i = 0;
  while (src[inc] != '\0')
    {
      while (i < 4)
	{
	  if (src[inc] == check[i])
	    {
	      tmp = my_cut_str(src, check[i], check[i]);
	      return (tmp);
	    }
	    i++;
	}
      i = 0;
      inc++;
    }
  return (NULL);
}
