/*
** my_str_to_worktab.c for my_str_to_worktab in /home/darrig_s/SYSTEME_UNIX
**
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
**
** Started on  Thu Jan 21 04:49:01 2016 Sophie Darrigol
** Last update Sun Jun  5 23:42:33 2016 RIMBAUD
*/

#include <stdlib.h>

char		**malloc_n2(char *str, char **av, int i)
{
  int		j;
  int		k;

  j = 0;
  k = 0;
  while ((str[i] == ' ' || str[i] == '\t') &&
	 str[i] != '\0')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  if ((av[k] = malloc((sizeof(char) * j) + 1)) == NULL)
	    return (NULL);
	  j = 0;
	  k++;
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
      i++;
      j++;
    }
  if ((av[k] = malloc((sizeof(char) * j) + 1)) == NULL)
    return (NULL);
  return (av);
}

char		**malloc_n1(char *str)
{
  int		i;
  int		nb_arg;
  char		**av;

  i = 0;
  nb_arg = 1;
  while ((str[i] == ' ' || str[i] == '\t') &&
	 str[i] != '\0')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	nb_arg = nb_arg + 1;
      while (str[i] == ' ' || str[i] == '\t')
	i++;
      i++;
    }
  if ((av = malloc((sizeof(char*) * nb_arg) + 1)) == NULL)
    return (NULL);
  av = malloc_n2(str, av, 0);
  return (av);
}

char		**my_str_to_worktab(char *str, int i, int j)
{
  char		**av;
  int		k;

  av = malloc_n1(str);
  k = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  av[k][j] = '\0';
	  j = 0;
	  k = k + 1;
	  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	    i++;
	}
      av[k][j++] = str[i++];
    }
  if (av[k][j - 1] == '\0')
    av[k] = NULL;
  return (av);
}
