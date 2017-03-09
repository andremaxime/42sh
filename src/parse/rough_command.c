/*
** rough_command.c for rough_command.c in /rendu/PSU_2015_minishell2/parse
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Wed Apr  6 15:05:32 2016 Vatoutine
** Last update Sun Jun  5 23:16:32 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"

int		my_fill_command(char **command)
{
  command[0] = "cd";
  command[1] = "env";
  command[2] = "setenv";
  command[3] = "unsetenv";
  return (0);
}

int		parse_rough_command(char *src)
{
  char		**command;
  int		inc;

  inc = 0;
  command = NULL;
  if ((command = malloc(sizeof(char *) * 5)) == NULL)
    return (-1);
  while (inc < 5)
    {
      command[inc] = NULL;
      inc ++;
    }
  inc = 0;
  my_fill_command(command);
  while (command[inc] != NULL)
    {
      if (my_compare(src, command[inc]) == 0)
        return (inc);
      inc++;
    }
  free(command);
  return (-1);
}
