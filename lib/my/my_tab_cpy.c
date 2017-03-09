/*
** my_tab_cpy.c for my_tab_cpy.c in /vatout_a/rendu/PSU_2015_minishell2/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Thu Mar 24 17:55:14 2016 Vatoutine
** Last update Thu Mar 24 18:05:09 2016 Vatoutine
*/

#include <stdlib.h>
#include "my.h"

char   **my_tab_cpy(char **src, char **dest)
{
  int  x;
  int  y;

  x = 0;
  y = 0;
  while (src[y] != NULL)
    {
      while (src[y][x] != '\0')
	{
	  dest[y][x] = src[y][x];
	  x++;
        }
      x = 0;
      y++;
    }
  return (dest);
}
