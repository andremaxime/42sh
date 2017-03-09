/*
** list.c for list.c in /home/vatout_a/rendu/PSU_2015_tetris/vatout_save/tools
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Tue Mar  1 11:53:51 2016 Vatoutine
** Last update	Wed Mar 02 14:08:58 2016 Vatoutine Artem
*/

#include <stdlib.h>
#include "my.h"
#include "struct.h"

void		my_free_list(t_list *env)
{
  t_funk	*funk;
  t_funk	*next;

  if (env->first != NULL)
    {
      funk = env->first;
      next = funk->next;
      while (next != NULL)
	{
	  next = funk->next;
	  free(funk->line);
	  free(funk);
	  funk = next;
	}
    }
  free(env);
}

t_list		*my_init_list(t_list *env)
{
  if ((env = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  env->length = 0;
  env->first = NULL;
  env->last = NULL;
  return (env);
}

t_list		*delete_elem(t_list *env, t_funk *funk)
{
  free(funk->line);
  if (env->length == 1)
    {
      env->first = NULL;
      env->last = NULL;
    }
  else if (funk->prev == NULL)
    {
      env->first = funk->next;
      funk->next->prev = NULL;
    }
  else if (funk->next == NULL)
    {
      env->last = funk->prev;
      funk->prev->next = NULL;
    }
  else
    {
      funk->prev->next = funk->next;
      funk->next->prev = funk->prev;
    }
  env->length--;
  return (env);
}

t_list		*add_elem_content(t_list *env, t_funk *funk, char *src)
{
  int		src_size;

  src_size = my_strlen(src);
  if ((funk->line = malloc(sizeof(char) * (src_size + 1))) == NULL)
    return (NULL);
  my_memset(funk->line, src_size);
  my_strcpy(funk->line, src);
  funk->next = NULL;
  return (env);
}

t_list		*add_elem(t_list *env, char *src)
{
  t_funk	*funk;

  if ((funk = malloc(sizeof(t_funk))) == NULL)
    return (NULL);
  env = add_elem_content(env, funk, src);
  if (env->last == NULL)
    {
      funk->prev = NULL;
      env->last = funk;
      env->first = funk;
    }
  else
    {
      funk->prev = env->last;
      env->last->next = funk;
      env->last = funk;
    }
  env->length++;
  return (env);
}
