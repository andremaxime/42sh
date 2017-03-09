/*
** find_redir.c for find redir or oper in /home/darrig_s/PROJETS/SYSTEME_UNIX/PSU_2015_42sh/test/redir
** 
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
** 
** Started on  Sun Jun  5 12:34:08 2016 Sophie Darrigol
** Last update Sun Jun  5 23:41:49 2016 RIMBAUD
*/

int		find_redir(char *str, char *to_find)
{
  int		i;
  int		j;

  i = -1;
  while (str[++i] != '\0')
    {
      j = 0;
      while (str[i] != '\0' && to_find[j] != '\0' &&
	     str[i] == to_find[j])
	{
	  i++;
	  j++;
	}
      if (to_find[j] == '\0')
	return (0);
    }
  return (-1);
}
