/*
** my_putchar.c for my_putchar.c in /home/vatout_a/lib/my
**
** Made by Vatoutine Artem
** Login   <vatout_a@epitech.net>
**
** Started on  Sun Nov 15 14:50:21 2015 Vatoutine Artem
** Last update	Tue Feb 23 19:55:36 2016 Vatoutine Artem
*/

#include <unistd.h>

int	my_putchar(char c)
{
  if ((write(1, &c, 1)) == -1)
    return (-1);
  return (0);
}
