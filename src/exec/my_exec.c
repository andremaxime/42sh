/*
** my_exec.c for my_exec.c in /home/vatout_a/epitech/USP/minishell
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Thu Jan 21 16:37:58 2016 Vatoutine
** Last update	Fri Jan 22 14:46:33 2016 Vatoutine Artem
*/

#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/types.h>
#include "my.h"

int		my_aout_exec(char **tab, char **envp)
{
  int		pid_s;
  int		state;

  if ((pid_s = fork()) < 0)
    return (0);
  if (pid_s == 0)
    if ((execve(tab[0], tab, envp)) == -1)
      return (-1);
  if (pid_s > 0)
    {
      waitpid(pid_s, &state, 0);
      if (state == 139 || state == 11)
        my_putstr("Segmentation fault\n");
    }
  return (0);
}

int		my_exec(char **tmp, char **command, char **envp, int res)
{
  int		pid_s;
  int		state;

  if ((pid_s = fork()) < 0)
    return (0);
  if (pid_s == 0)
    if ((execve(tmp[res], command, envp)) == -1)
      return (-1);
  if (pid_s > 0)
    waitpid(pid_s, &state, 0);
  if (state == 139 || state == 11)
    my_putstr("Segmentation fault\n");
  return (0);
}
