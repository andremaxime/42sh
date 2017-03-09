/*
** my_putchar_error.c for my_putchar_error.c in /home/vatout_a/rendu/PSU_2015_tetris/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Sun Mar 20 02:16:27 2016 Vatoutine
** Last update Sun Mar 20 02:20:55 2016 Vatoutine
*/

#include <unistd.h>

int	my_putchar_error(char z)
{
  if (write(2, &z, 1) == -1)
    return (-1);
  return (0);
}
