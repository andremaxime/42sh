/*
** use_env.c for use_env.c in /home/vatout_a/rendu/PSU_2015_minishell2/env
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Fri Apr  1 16:31:23 2016 Vatoutine
** Last update Sun Jun  5 23:07:50 2016 RIMBAUD
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char		*my_parse_list_env(t_list *env, char *var)
{
  char		*src;
  t_funk	*funk;
  int		src_size;

  funk = env->first;
  while (funk != NULL)
    {
      if ((my_compare(funk->line, var)) == 0)
	{
	  src_size = my_strlen(funk->line);
	  if ((src = malloc(sizeof(char) * (src_size + 1))) == NULL)
	    return (NULL);
	  my_memset(src, src_size);
	  my_strcpy(src, funk->line);
	  if ((src = my_cut_str(src, '=', '\0')) == NULL)
	    return (NULL);
	  return (src);
        }
      funk = funk->next;
    }
  return (NULL);
}

char		*my_parse_tab_env(t_list *env, char *src)
{
  t_funk	*funk;
  char		*tmp;
  int		src_size;

  if ((funk = find_elem(env, src)) == NULL)
    return (NULL);
  src_size = my_strlen(funk->line);
  if ((tmp = malloc(sizeof(char) * (src_size + 1))) == NULL)
    return (NULL);
  my_memset(tmp, src_size);
  my_strcpy(tmp, funk->line);
  tmp = my_cut_str(tmp, '=', '\0');
  return (tmp);
}

t_funk		*find_elem(t_list *env, char *src)
{
  t_funk	*funk;

  funk = env->first;
  while (funk != NULL)
    {
      if (my_compare(funk->line, src) == 0)
	return (funk);
      funk = funk->next;
    }
  return (NULL);
}
