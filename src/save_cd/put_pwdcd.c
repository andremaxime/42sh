/*
** get_cd.c for  in /home/andre/systemeunix/PSU_2015_minishell2
**
** Made by andre
** Login   <andre@epitech.net>
**
** Started on  Sat Mar 26 02:12:23 2016 andre
** Last update Sun Jun  5 23:25:13 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

char		*put_pwd(char *str)
{
  char		*tmp;
  int		i;

  i = 0;
  if ((tmp = malloc(my_strlen(str) + 5)) == NULL)
    return ("PWD=.");
  tmp = my_strcpy(tmp, "PWD=");
  while (tmp[i] != '=')
    i++;
  i++;
  tmp[i] = '\0';
  tmp = my_strcat2(tmp, str, 1);
  return (tmp);
}

int		changepwd(char *chemin, t_list *list)
{
  t_funk	*elem;
  int		size;

  if ((elem = malloc(sizeof(t_funk *))) == NULL)
    return (-1);
  size = list->length;
  elem = list->first;
  while (size != 0)
    {
      if (check_debut("PWD", elem->line) == 0)
	{
	  chemin = put_pwd(chemin);
	  return (0);
	}
      elem = elem->next;
      size--;
    }
  return (0);
}
