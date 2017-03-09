/*
** my_getnbr.c for my_getnbr.c in /home/vatout_a/lib/my
**
** Made by Vatoutine Artem
** Login   <vatout_a@epitech.net>
**
** Started on  Sun Nov 15 14:26:24 2015 Vatoutine Artem
** Last update Tue Apr  5 17:16:52 2016 Vatoutine
*/

int	my_getnbr(char *src)
{
  int	inc;
  int	res;
  int	tmp;

  res = 0;
  tmp = 0;
  if (src[0] == '-')
    inc = 1;
  else
    inc = 0;
  while (src[inc] <= '9' && src[inc] >= '0')
    {
      res = res * 10;
      tmp = src[inc] - 48;
      res = res + tmp;
      inc++;
    }
  if (res > 0 && src[0] == '-')
    res = res * -1;
  return (res);
}
