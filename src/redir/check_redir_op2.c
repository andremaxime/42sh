/*
** check_redir_op2.c for check 2 in /home/darrig_s/PSU_2015_42sh/test/redir
** 
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
** 
** Started on  Sun Jun  5 22:58:11 2016 Sophie Darrigol
** Last update Sun Jun  5 23:39:35 2016 RIMBAUD
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char		**malloc_cut_str(char *src, char **to_exec)
{
  int		i;

  i = -1;
  if ((to_exec = malloc(sizeof(char *) * 2)) == NULL)
    return (NULL);
  while (src[++i] != '\0' && src[i] != '<' &&
	          src[i] != '>' && src[i] != '&' &&
	 src[i] != '|');
  if ((to_exec[0] = malloc(sizeof(char) * i + 1)) == NULL)
    return (NULL);
  return (to_exec);
}

char		**cut_str(char  *src, char **to_exec, int i)
{
  int		j;

  if ((to_exec = malloc_cut_str(src, to_exec)) == NULL)
    return (NULL);
  j = 0;
  while (src[++i] != '\0')
    {
      if (src[i] == '<' || src[i] == '>' || src[i] == '&' || src[i] == '|')
	{
	  to_exec[0][j] = '\0';
	  if ((to_exec[1] = malloc(sizeof(char) * my_strlen(src) - i)) == NULL)
	    return (NULL);
	  if ((src[i] == '<' && src[i + 1] == '<') ||
	      (src[i] == '>' && src[i + 1] == '>') ||
	      (src[i] == '&' && src[i + 1] == '&') ||
	      (src[i] == '|' && src[i + 1] == '|'))
	    to_exec[1] = &src[i + 3];
	  else
	    to_exec[1] = &src[i + 2];
	  return (to_exec);
	}
      to_exec[0][j++] = src[i];
    }
  return (NULL);
}
