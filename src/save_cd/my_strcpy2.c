/*
** my_strcpy2.c for  in /home/andre_c/systemeunix/PSU_2015_42sh/minishell2/cd
**
** Made by andre
** Login   <andre_c@epitech.net>
**
** Started on  Fri Jun  3 20:18:00 2016 andre
** Last update Sun Jun  5 23:24:17 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"

int		check_cd(char **tmp)
{
  int		i;

  i = 0;
  while (tmp[i] != NULL)
    i++;
  if (i > 2)
    {
      my_putstr("cd: Too many arguments.\n");
      return (-1);
    }
  return (0);
}

int		check_debut(char *sa, char *sb)
{
  int		i;

  i = 0;
  while (sa[i] != '\0')
    {
      if (sa[i] != sb[i])
        return (1);
      i++;
    }
  return (0);
}

char		*my_strcat2(char *dest, char *src, int a)
{
  int		i;
  int		z;

  i = 0;
  z = 0;
  if (a == 0)
    z = 0;
  else
    while (dest[z] != '\0')
      z++;
  while (src[i] != '\0')
    {
      dest[z] = src[i];
      z++;
      i++;
    }
  dest[z] = '\0';
  return (dest);
}

char		*my_strcpy2(char *str)
{
  char		*tmp;
  int		i;

  i = 0;
  if ((tmp = malloc(my_strlen(str) + 2)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}
