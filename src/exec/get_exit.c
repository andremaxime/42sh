/*
** get_exit.c for  in /home/andre_c/systemeunix/PSU_2015_42sh/minishell2/exec
**
** Made by andre
** Login   <andre_c@epitech.net>
**
** Started on  Thu Jun  2 11:33:59 2016 andre
** Last update Sun Jun  5 23:38:07 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

int		trouv_sortie(char *src)
{
  char		**tab;
  int		i;
  int		nb;

  i = 0;
  tab = NULL;
  if ((tab = my_str_to_wordtab(tab, src, ' ')) == NULL)
    return (1);
  if (tab[1] == NULL)
    return (0);
  while (tab[1][i] != '\0')
    {
      if ((tab[1][i] < 48 || tab[1][i] > 57) && tab[1][i] != '-')
	{
	  my_putstr("exit: Expression Syntax.\n");
	  my_tab_free(tab);
	  return (-12);
	}
      i++;
    }
  nb = my_getnbr(tab[1]);
  my_tab_free(tab);
  return (nb);
}

int		get_exit(t_list *env, char *src)
{
  int		sortie;

  if ((sortie = trouv_sortie(src)) == 12)
    return (0);
  if (src != NULL)
    free(src);
  if (env != NULL)
    my_free_list(env);
  my_putstr("exit\n");
  exit(sortie);
}
