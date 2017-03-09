/*
** get_cd.c for  in /home/andre/systemeunix/PSU_2015_minishell2
**
** Made by andre
** Login   <andre@epitech.net>
**
** Started on  Sat Mar 26 02:12:23 2016 andre
** Last update Sun Jun  5 23:22:42 2016 RIMBAUD
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"

int		do_cd2(char *home, char **tmp, char *old)
{
  char		*tmp1;

  if ((tmp1 = malloc(my_strlen(tmp[1]) * my_strlen(home))) == NULL)
    return (-1);
  if (my_strcmp(tmp[1], "~") == 0)
    {
      test_home(home);
      if (chdir(home) == -1)
	return (0);
      return (1);
    }
  if (my_compare("~/", tmp[1]) == 0)
    {
      test_home(home);
      tmp1 = my_strcpy2(home);
      tmp1 = my_strcat2(tmp1, "/", 1);
      tmp1 = my_strcat2(tmp1, tmp[1], 1);
      if (chdir(tmp1) == -1)
	return (0);
      return (1);
    }
  if (do_cd3(home, tmp, old) == 1)
    return (1);
  return (0);
}

int		do_cd(char *chemin, char **tmp, t_list *list, char *saveold)
{
  char		*home;
  char		*old;

  home = recup_home(list, "HOME");
  old = recup_home(list, "OLDPWD");
  if (saveold != NULL)
    {
      if ((my_strcmp(old, ".") == 0) && saveold[0] == '/')
	old = my_strcpy2(saveold);
    }
  chemin = my_strcat2(chemin, "/", my_strlen(chemin));
  if (tmp[1] == NULL)
    {
      test_home_cd(home);
      chdir(home);
    }
  else
    {
      if (do_cd2(home, tmp, old) == 1)
	return (0);
      chemin = my_strcat2(chemin, tmp[1], my_strlen(chemin));
      if (chdir(chemin) == -1)
	return (-1);
    }
  return (0);
}

int		do_oldpwd(t_list *list, char *cool)
{
  char		*nouv;
  int		i;
  int		z;

  i = 0;
  if ((nouv = malloc(sizeof(char) * (my_strlen(cool) + 15))) == NULL)
    return (1);
  my_memset(nouv, my_strlen(cool));
  nouv = my_strcpy(nouv, "setenv OLDPWD ");
  z = my_strlen(nouv);
  while (cool[i] != '\0')
    nouv[z++] = cool[i++];
  nouv[z] = '\0';
  go_env(list, nouv);
  free(nouv);
  return (0);
}

int		get_cd(t_list *list, char *str)
{
  char		**tmp;
  char		chemin[4096];
  char		chemin2[4096];
  char		*cool;
  static char	*saveold;

  saveold = saveold;
  tmp = NULL;
  tmp = my_str_to_wordtab(tmp, str, ' ');
  if ((check_cd(tmp) == -1) || ((cool = malloc(my_strlen(chemin))) == NULL))
    return (0);
  getcwd(chemin, 4096);
  cool = my_strcpy2(chemin);
  if (do_cd(chemin, tmp, list, saveold) == -1)
    {
      display_error_cd(tmp[1]);
      return (0);
    }
  else
    do_oldpwd(list, cool);
  saveold = my_strcpy2(cool);
  getcwd(chemin2, 4096);
  changepwd(chemin2, list);
  free(cool);
  return (0);
}
