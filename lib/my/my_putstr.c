/*
** my_putstr.c for my_putstr.c in /home/vatout_a/lib/my
**
** Made by Vatoutine Artem
** Login   <vatout_a@epitech.net>
**
** Started on  Sun Nov 15 14:51:28 2015 Vatoutine Artem
** Last update	Tue Feb 23 19:56:03 2016 Vatoutine Artem
*/

#include "my.h"

int	my_putstr(char *str)
{
  int inc;

  inc = 0;
  while (str[inc] != '\0')
    {
      if ((my_putchar(str[inc])) == -1)
        return (-1);
      inc++;
    }
  return (0);
}
