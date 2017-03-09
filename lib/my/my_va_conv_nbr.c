/*
** my_va_conv_nbr.c for my_va_conv_nbr.c in /home/vatout_a/lib/my
**
** Made by Vatoutine Artem
** Login   <vatout_a@epitech.net>
**
** Started on  Sun Nov 15 15:04:19 2015 Vatoutine Artem
** Last update	Wed Feb 10 18:25:36 2016 Vatoutine Artem
*/

#include <stdarg.h>
#include "my.h"

void	my_put_ld(long nb)
{
  int	a;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * - 1;
    }
  if (nb > 0)
    {
      a = nb % 10;
      nb = nb / 10;
      my_put_ld(nb);
      my_putchar(a + 48);
    }
}

int	my_va_conv_ld(va_list ap)
{
  long	nb;

  nb = va_arg(ap, long);
  my_put_ld(nb);
  return (0);
}

int	my_va_conv_nbr(va_list ap)
{
  int	nb;

  nb = va_arg(ap, int);
  my_put_nbr(nb);
  return (0);
}
