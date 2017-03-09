/*
** my_strcmp.c for my_strcmp.c in /rendu/PSU_2015_tetris/vatout_save/lib/my
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Tue Feb 23 21:43:05 2016 Vatoutine
** Last update	Tue Mar 01 10:31:32 2016 Vatoutine Artem
*/

int	my_strcmp(char *word1, char *word2)
{
  while (*word1 && *word2 && *word1 == *word2)
    {
      ++word1;
      ++word2;
    }
  return (*word1 - *word2);
}
