/*
** set_env.c for set_env.c in /home/vatout_a/rendu/PSU_2015_minishell2/env
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Fri Apr  1 16:43:21 2016 Vatoutine
** Last update Sun Jun  5 23:07:03 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"

t_funk		*find_env_var(t_list *env, char *var)
{
  char		*tmp;
  t_funk	*funk;

  funk = env->first;
  while (funk != NULL)
    {
      tmp = my_cut_until(funk->line, '=');
      if (my_compare(var, tmp) == 0)
        {
          free(tmp);
          return (funk);
        }
      funk = funk->next;
      free(tmp);
    }
  return (NULL);
}

int		unset_env(t_list *env, char *var)
{
  t_funk	*funk;
  char		**tab;
  int		i;

  tab = NULL;
  i = 0;
  tab = my_str_to_wordtab(tab, var, ' ');
  while (tab[++i] != NULL)
    {
      if (my_strcmp(tab[i], "*") == 0)
	delete_all(env);
      else if ((funk = find_env_var(env, tab[i])) == NULL)
	continue;
      else
	env = delete_elem(env, funk);
    }
  my_tab_free(tab);
  return (0);
}

int		create_env(t_list *env, char *var, char *content)
{
  int		src_size;
  char		*tmp;

  tmp = NULL;
  if (var == NULL)
    return (-1);
  if (content == NULL)
    src_size = my_strlen(var) + 1;
  else
    src_size = my_strlen(var) + my_strlen(content) + 1;
  if ((tmp = malloc(sizeof(char) * (src_size + 1))) == NULL)
    return (-1);
  my_memset(tmp, src_size);
  my_strcpy(tmp, var);
  my_strcat(tmp, "=");
  if (content != NULL)
    my_strcat(tmp, content);
  add_elem(env, tmp);
  return (0);
}

int		set_env(t_list *env, char *var, char *content)
{
  t_funk	*funk;
  char		*tmp;
  int		src_size;

  if ((funk = find_elem(env, var)) == NULL)
    create_env(env, var, content);
  else
    {
      if (content == NULL)
        src_size = my_strlen(var) + 1;
      else
        src_size = my_strlen(var) + my_strlen(content) + 1;
      if ((tmp = malloc(sizeof(char) * (src_size + 1))) == NULL)
        return (-1);
      my_memset(tmp, src_size);
      my_strcpy(tmp, var);
      my_strcat(tmp, "=");
      if (content != NULL)
        my_strcat(tmp, content);
      free(funk->line);
      funk->line = tmp;
    }
  return (0);
}

int		go_env(t_list *env, char *src)
{
  char		*var;
  char		*content;
  char		*tmp;

  if ((var = my_cut_str(src, ' ', '\0')) == NULL)
    return (-1);
  if ((content = my_cut_str(var, ' ', '\0')) == NULL)
    return (-1);
  var = my_cut_str(src, ' ', ' ');
  if ((tmp = remove_quotes(content)) == NULL)
    set_env(env, var, content);
  else
    set_env(env, var, tmp);
  return (0);
}
