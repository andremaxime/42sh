/*
** find_path.c for  in /home/maison_f/Epitech/rendu/PSU_2015_42sh/minishell2/pipe
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sat Jun  4 00:40:55 2016 Maisonnave Florian
** Last update Sun Jun  5 23:18:22 2016 RIMBAUD
*/

#include "pipe.h"
#include "my.h"

int		find_pwd(char **env)
{
  char		*str;
  int		tmp;
  int		i;
  int		k;

  i = 0;
  k = 0;
  tmp = 0;
  str = "PWD=";
  while (env[i] != NULL)
    {
      while (env[i][k] == str[k] && k < 5)
	{
	  tmp = i;
	  k++;
	}
      if (k < 4)
	k = 0;
      i++;
    }
  if (k >= 4)
    return (tmp);
  return (-1);
}

char		*save_path(char **env, int tmp)
{
  char		*path;
  int		pwd;
  int		i;
  int		k;

  i = 0;
  k = 5;
  pwd = find_pwd(env);
  path = malloc(sizeof(char) * (my_strlen(env[tmp]) + my_strlen(env[pwd])));
  while (env[tmp][k])
    path[i++] = env[tmp][k++];
  k = 4;
  path[i] = ':';
  i++;
  while (env[pwd][k])
    path[i++] = env[pwd][k++];
  path[i] = '\0';
  return (path);
}

char		*find_path(char **env)
{
  char		*str;
  int		tmp;
  int		i;
  int		k;

  i = 0;
  k = 0;
  tmp = 0;
  str = "PATH=";
  while (env[i] != NULL)
    {
      while (env[i][k] == str[k] && k < 5)
	{
	  tmp = i;
	  k++;
	}
      if (k < 5)
	k = 0;
      i++;
    }
  if (k >= 5)
    return (save_path(env, tmp));
  return (NULL);
}

char		**create_path(char **env)
{
  char		**path;
  char		*str;

  if (*env != NULL)
    {
      path = NULL;
      if ((str = find_path(env)) == NULL)
	return (NULL);
      path = my_str_to_wordtab(path, str, ':');
      free(str);
      return (path);
    }
  return (NULL);
}
