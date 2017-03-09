/*
** my_epur_str.c for my_epur_str.c in /vatout_a/rendu/PSU_2015_minishell2/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Thu Mar 24 17:22:31 2016 Vatoutine
** Last update Sun Jun  5 04:19:30 2016 andre
*/

#include <stdlib.h>
#include "my.h"

char	*my_epur_str(char *src)
{
  int	z;
  int	y;
  char  *dest;

  z = 0;
  y = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  my_memset(dest, my_strlen(src));
  while ((src[z] == 32) || (src[z] == '\t'))
    z++;
  while (src[z] != '\0')
    {
      if ((src[z] == 32) || (src[z] == '\t'))
	{
	  dest[y++] = 32;
	  while ((src[z] == 32) || (src[z] == '\t'))
	    z++;
	}
      dest[y++] = src[z++];
    }
  if ((dest[y - 2] == 32) && (dest[y - 1] == '\0'))
    dest[y - 2] = '\0';
  free(src);
  return (dest);
}
