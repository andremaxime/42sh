/*
** my_parse.c for my_parse.c in /home/vatout_a/epitech/USP/minishell
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Thu Jan 21 10:36:47 2016 Vatoutine
** Last update	Fri Jan 22 15:11:51 2016 Vatoutine Artem
*/

#include <stdlib.h>
#include "my.h"

t_tab		*my_tab_length(char **tab, t_tab *tab_size)
{
  int		inc;

  inc = 0;
  if ((tab_size = malloc(sizeof(t_tab))) == NULL)
    return (NULL);
  tab_size->words = 0;
  while (tab[inc] != NULL)
    {
      tab_size->words++;
      inc++;
    }
  if ((tab_size->word = malloc(sizeof(int) * (tab_size->words + 1))) == NULL)
    return (NULL);
  my_memset_int(tab_size->word, tab_size->words);
  inc = 0;
  while (tab[inc] != NULL)
    {
      tab_size->word[inc] = my_strlen(tab[inc]);
      inc++;
    }
  return (tab_size);
}

char		**my_parse(char **path, t_list *env, char *src)
{
  char		*excalibur;
  char		*nouv;
  int		i;

  if ((excalibur = my_parse_tab_env(env, src)) == NULL)
    return (NULL);
  if ((nouv = malloc(my_strlen(excalibur) + 1)) == NULL)
    return (NULL);
  nouv = my_strcpy(nouv, excalibur);
  i = my_strlen(nouv);
  nouv[i++] = ':';
  nouv[i] = '\0';
  path = my_str_to_wordtab(path, nouv, ':');
  free(excalibur);
  free(nouv);
  return (path);
}
