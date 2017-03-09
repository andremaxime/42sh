/*
** my_cut_str.c for my_cut_str.c in /home/vatout_a/rendu/prepare/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Mon Mar 21 15:35:51 2016 Vatoutine
** Last update Sun Jun  5 22:19:36 2016 Maisonnave Florian
*/

#include <stdlib.h>
#include "my.h"

char		*my_check_str(char *src, char a, char b)
{
  int		inc;

  inc = 0;
  while (src[inc] != '\0')
    {
      if (src[inc] == a)
	{
	  while (src[inc] != '\0')
	    {
	      if (src[inc + 1] == b)
		return (src);
	      inc++;
            }
        }
      inc++;
    }
  return (NULL);
}

char		*my_cut_str(char *src, char a, char b)
{
  int		inc;
  int		zero;
  char		*dest;

  if ((my_check_str(src, a, b)) == NULL)
    return (NULL);
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  my_memset(dest, my_strlen(src));
  inc = 0;
  zero = 0;
  while (src[inc] != a)
    inc++;
  inc++;
  while (src[inc] != b)
    {
      dest[zero] = src[inc];
      zero++;
      inc++;
    }
  return (dest);
}
