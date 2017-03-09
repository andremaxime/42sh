/*
** main.c for  in /home/andre_c/systemeunix/PSU_2015_42sh/test/triple
**
** Made by andre
** Login   <andre_c@epitech.net>
**
** Started on  Fri Jun  3 22:11:38 2016 andre
** Last update Sun Jun  5 23:19:22 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"

int		count_pipe(char *str)
{
  int		i;
  int		pipe;

  i = 0;
  pipe = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '|')
	pipe++;
      i++;
    }
  return (pipe);
}

char		*epur_triple(char *str)
{
  char		*tmp;
  int		i;
  int		z;

  if ((tmp = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  i = 0;
  z = 0;
  while (str[i] != '\0')
    {
      if ((str[i] == ' ' && str[i + 1] == '|') ||
	  (str[i] == ' ' && str[i - 1] == '|'))
	i++;
      if (str[i] != '\0')
	{
	  tmp[z] = str[i];
	  i++;
	}
      z++;
    }
  tmp[z] = '\0';
  return (tmp);
}

char		***init_triple(char *str)
{
  int		i;
  int		pipe;
  char		***tab;
  char		**pi;

  i = 0;
  str = epur_triple(str);
  pipe = count_pipe(str) + 1;
  if ((tab = malloc(pipe * sizeof(char *) * sizeof(char *))) == NULL)
    return (NULL);
  pi = NULL;
  pi = my_str_to_wordtab(pi, str, '|');
  while (i != pipe)
    {
      tab[i] = my_str_to_wordtab(tab[i], pi[i], ' ');
      i++;
    }
  my_tab_free(pi);
  tab[i] = NULL;
  return (tab);
}
