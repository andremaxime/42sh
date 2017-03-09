/*
** error_cd.c for 42sh in /home/rimbaud/rendu/unix/PSU_2015_42sh/minishell2/save_cd
**
** Made by RIMBAUD
** Login   <rimbau_m@epitech.net>
**
** Started on  Sun Jun  5 03:17:20 2016 RIMBAUD
** Last update Sun Jun  5 23:21:27 2016 RIMBAUD
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my.h"

int		display_error_cd(char *str)
{
  struct stat	*file;

  if ((file = malloc(sizeof(struct stat))) == NULL)
    return (1);
  stat(str, file);
  if (S_ISREG(file->st_mode) == 1)
    {
      my_putstr(str);
      my_putstr(": Not a directory.\n");
    }
  else if (file->st_mode != S_IRWXU && S_ISDIR(file->st_mode) == 1)
    {
      my_putstr(str);
      my_putstr(": Permission denied.\n");
    }
  else
    {
      my_putstr(str);
      my_putstr(": No such file or directory.\n");
    }
  free(file);
  return (0);
}
