/*
** my_cut_until.c for my_cut_until.c in /home/vatout_a/rendu/prepare/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Mon Mar 21 15:44:23 2016 Vatoutine
** Last update Sun Jun  5 22:19:57 2016 Maisonnave Florian
*/

#include <stdlib.h>
#include "my.h"

char		*my_cut_until(char *src, char z)
{
  int		inc;
  int		src_size;
  char		*dest;

  inc = 0;
  src_size = my_strlen(src);
  if ((dest = malloc(sizeof(char) * (src_size + 1))) == NULL)
    return (NULL);
  my_memset(dest, src_size);
  while (src[inc] != z)
    {
      dest[inc] = src[inc];
      inc++;
    }
  return (dest);
}
