/*
** my_memset.c for my_memset.c in /PSU_2015_tetris/vatout_save/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Wed Mar  9 21:44:49 2016 Vatoutine
** Last update Mar 24 14:10:19 2016
*/

char	*my_memset(char *src, int size)
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
