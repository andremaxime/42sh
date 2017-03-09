/*
** recup_home.c for  in /home/andre/systemeunix/PSU_2015_minishell2
**
** Made by andre
** Login   <andre@epitech.net>
**
** Started on  Sun Mar 27 00:41:09 2016 andre
** Last update Sun Jun  5 23:26:23 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

char		*recup_var(char *tmp, char *str)
{
  int		i;
  int		z;

  i = 0;
  z = 0;
  while (str[i] != '=' && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    return (".");
  i++;
  while (str[i] != '\0')
    {
      tmp[z] = str[i];
      z++;
      i++;
    }
  tmp[z] = '\0';
  return (tmp);
}

char		*recup_home(t_list *list, char *str)
{
  char		*tmp;
  t_funk	*elem;
  int		size;

  if ((elem = malloc(sizeof(t_funk *))) == NULL)
    return (".");
  size = list->length;
  elem = list->first;
  while (size != 0)
    {
      if (check_debut(str, elem->line) == 0)
	{
	  if ((tmp = malloc(my_strlen(elem->line))) == NULL)
	    return (".");
	  tmp = recup_var(tmp, elem->line);
	  return (tmp);
	}
      size--;
      elem = elem->next;
    }
  return (".");
}
