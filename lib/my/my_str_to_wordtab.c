/*
** my_str_towordtab.c for my_str_to_wordtab.c in /vatout_save/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Fri Mar  4 13:59:37 2016 Vatoutine
** Last update Sun Jun  5 22:20:52 2016 Maisonnave Florian
*/

#include <stdlib.h>
#include "my.h"

char		**my_tab_fill(char **tab, char *src, char z)
{
  int		inc;
  int		x;
  int		y;

  inc = 0;
  y = 0;
  x = 0;
  while (src[inc] != '\0')
    {
      if (src[inc] == z)
	{
	  y++;
	  x = 0;
	}
      else
	{
	  tab[y][x] = src[inc];
          x++;
	}
      inc++;
    }
  return (tab);
}

char		**my_tab_init(t_tab *tab_size, char **tab)
{
  int		inc;

  inc = 0;
  if ((tab = malloc(sizeof(char *) * (tab_size->words + 1))) == NULL)
    return (NULL);
  while (inc < tab_size->words)
    {
      if ((tab[inc] = malloc(sizeof(char) *
	   (tab_size->word[inc] + 1))) == NULL)
	return (NULL);
      my_memset(tab[inc], tab_size->word[inc]);
      inc++;
    }
  tab[inc] = NULL;
  return (tab);
}

int		my_tab_word_nbr(char *src, char z)
{
  int		inc;
  int		res;

  inc = 0;
  res = 0;
  while (src[inc] != '\0')
    {
      if (src[inc] == z)
	res++;
      inc++;
    }
  res++;
  return (res);
}

t_tab		*my_tab_size(t_tab *tab_size, char *src, char z)
{
  int		inc;
  int		save;
  int		word;

  inc = 0;
  save = 0;
  word = 0;
  while (src[inc] != '\0')
    {
      if (src[inc] == z || src[inc + 1] == '\0')
	{
	  tab_size->word[word] = (save + 1);
          word++;
	  save = 0;
	}
      else
	save++;
      inc++;
    }
  return (tab_size);
}

char		**my_str_to_wordtab(char **tab, char *src, char z)
{
  t_tab		*tab_size;

  if (src == NULL)
    return (NULL);
  tab_size = NULL;
  if ((tab_size = malloc(sizeof(t_tab))) == NULL)
    return (NULL);
  tab_size->words = my_tab_word_nbr(src, z);
  if ((tab_size->word = malloc(sizeof(int) * (tab_size->words + 1))) == NULL)
    return (NULL);
  tab_size = my_tab_size(tab_size, src, z);
  if ((tab = my_tab_init(tab_size, tab)) == NULL)
    return (NULL);
  tab = my_tab_fill(tab, src, z);
  free(tab_size->word);
  free(tab_size);
  return (tab);
}
