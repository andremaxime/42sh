/*
** check_redir_op.c for check redirection + operator in /home/darrig_s/PROJETS/SYSTEME_UNIX/PSU_2015_42sh/test/redir
**
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
**
** Started on  Sun Jun  5 10:56:48 2016 Sophie Darrigol
** Last update Sun Jun  5 23:40:10 2016 RIMBAUD
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int             my_init_tabredir(int (*tab_redir[6])(t_list *, char **))
{
  tab_redir[0] = doubleet;
  tab_redir[1] = doubleou;
  return (0);
}

int             my_fill_compar(char *tab[2])
{
  tab[0] = "&&";
  tab[1] = "||";
  return (0);
}

int		check_tab(char *src, t_list *envp)
{
  char		**to_exec;
  char		*redir[6];
  int		i;
  int		(*tab_redir[6])(t_list *, char **);

  i = -1;
  to_exec = NULL;
  my_fill_compar(redir);
  to_exec = cut_str(src, to_exec, -1);
  my_init_tabredir(tab_redir);
  while (++i < 6)
    if (find_redir(src, redir[i]) == 0)
      {
  	tab_redir[i](envp, to_exec);
  	return (0);
      }
  free(to_exec[0]);
  free(to_exec);
  return (0);
}

int		check_redir_op(char *src)
{
  int		i;
  int		yes;

  i = -1;
  yes = 0;
  while (src[++i] != '\0')
    {
      if ((src[i] == '&' && src[i + 1] == '&') ||
	  (src[i] == '|' && src[i + 1] == '|'))
	    yes = i;
    }
  if (yes == 0)
    return (-1);
  return (0);
}
