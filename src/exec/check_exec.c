/*
** check_exec.c for check_exec.c in /home/vatout_a/rendu/PSU_2015_minishell2
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Thu Mar 24 17:12:10 2016 Vatoutine
** Last update Sun Jun  5 23:09:32 2016 RIMBAUD
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int		my_check_access(char **tmp)
{
  int		inc;
  int		res;

  inc = 0;
  res = -1;
  while (tmp[inc] != NULL)
    {
      if (access(tmp[inc], F_OK) == 0)
	res = inc;
      inc++;
    }
  return (res);
}

char		**concat_command(char **path, char **tmp, char *command)
{
  int		inc;
  int		y;
  int		x;

  y = 0;
  inc = 0;
  tmp = my_tab_cpy(path, tmp);
  while (tmp[y] != NULL)
    {
      x = my_strlen(tmp[y]);
      tmp[y][x] = 47;
      x++;
      while (command[inc] != '\0')
	{
	  tmp[y][x] = command[inc];
	  x++;
	  inc++;
        }
      inc = 0;
      x = 0;
      y++;
    }
  return (tmp);
}

char		**tab_realloc(char **tmp, t_tab *tab_size, char *command)
{
  int		inc;
  int		tsize;

  inc = 0;
  if ((tmp = malloc(sizeof(char *) * (tab_size->words + 1))) == NULL)
    return (NULL);
  while (inc < tab_size->words)
    {
      tsize = tab_size->word[inc] + (my_strlen(command));
      if ((tmp[inc] = malloc(sizeof(char) * (tsize + 2))) == NULL)
	return (NULL);
      my_memset(tmp[inc], tsize + 1);
      inc++;
    }
  tmp[inc] = NULL;
  return (tmp);
}

char		**check_exec(char **path, char **command)
{
  t_tab		*tab_size;
  char		**tmp;

  tmp = NULL;
  tab_size = NULL;
  tab_size = my_tab_length(path, tab_size);
  tmp = tab_realloc(tmp, tab_size, command[0]);
  tmp = concat_command(path, tmp, command[0]);
  free(tab_size->word);
  free(tab_size);
  return (tmp);
}
