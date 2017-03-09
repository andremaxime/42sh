/*
** my_putstr_error.c for my_putstr_error.c in /home/vatout_a/rendu/PSU_2015_tetris/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Sun Mar 20 02:14:42 2016 Vatoutine
** Last update Sun Mar 20 02:22:47 2016 Vatoutine
*/

#include "my.h"

int	my_putstr_error(char *src)
{
  int	inc;

  inc = 0;
  while (src[inc] != '\0')
    {
      if (my_putchar_error(src[inc]) == -1)
	return (-1);
      inc++;
    }
  return (0);
}
