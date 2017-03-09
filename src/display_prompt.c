/*
** display_prompt.c for  in /home/andre_c/systemeunix/PSU_2015_42sh/minishell2
**
** Made by andre
** Login   <andre_c@epitech.net>
**
** Started on  Sun Jun  5 18:46:42 2016 andre
** Last update Sun Jun  5 23:01:38 2016 RIMBAUD
*/

#include <stdlib.h>
#include "my.h"
#include "get_next_line.h"

int		my_newprompt(char prompt[4096], char *s)
{
  int		i;
  int		z;

  i = 0;
  z = 0;
  while (s[i] != ' ' && s[i + 1] != '\0')
    i++;
  i++;
  if (s[i] == '\0')
    return (0);
  while (prompt[z] != '\0')
    prompt[z++] = '\0';
  z = 0;
  while (s[i] != '\0')
    prompt[z++] = s[i++];
  prompt[z++] = '>';
  prompt[z] = '\0';
  return (0);
}

char		*display_prompt(char *s)
{
  static char	prompt[4096] = "$> ";

  my_putstr(prompt);
  if (((s = get_next_line(0)) == NULL) || s[0] == '\0')
    return (NULL);
  s = my_epur_str(s);
  if (my_compare(s, "prompt") == 0)
    {
      if (my_strcmp("prompt", s) == 0)
	my_putstr("prompt: needs an argument.\n");
      my_newprompt(prompt, s);
      free(s);
      return (NULL);
    }
  return (s);
}
