/*
** my_memset_int.c for my_memset_int.c in /rendu/PSU_2015_minishell2/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Thu Mar 24 14:10:39 2016 Vatoutine
** Last update Mar 24 14:21:14 2016
*/

int	*my_memset_int(int *src, int size)
{
  int	inc;

  inc = 0;
  while (inc <= size)
    {
      src[inc] = '\0';
      inc++;
    }
  return (src);
}
