/*
** error_sys.c for error_sys.c in /home/vatout_a/rendu/PSU_2015_minishell2
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Fri Mar 25 16:42:28 2016 Vatoutine
** Last update Sun Jun  5 23:08:23 2016 RIMBAUD
*/

#include "my.h"

int		error_sys(int error, char *src)
{
  if ((error == 2) || (error == 1))
    {
      my_putstr(src);
      my_putstr_error(": Command not found.\n");
      return (-1);
    }
  return (-1);
}
