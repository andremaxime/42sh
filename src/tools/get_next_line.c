/*
** get_next_line.c for get next line in /home/darrig_s/PROJETS/CPE_2015_getnextline
**
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
**
** Started on  Tue Mar  8 04:39:12 2016 Sophie Darrigol
** Last update Sun Jun  5 23:28:18 2016 RIMBAUD
*/

#include <stdio.h>
#include "get_next_line.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str && str[i] != '\0')
    i = i + 1;
  return (i);
}

int		find_str(char *str)
{
  int		i;

  i = -1;
  if (str != NULL)
    while (str[++i] != '\0')
      if (str[i] == '\n')
	return (i);
  return (-2);
}

char		*find_line(char *str, int i)
{
  int		k;
  char		*tmp;

  k = -1;
  if (i != -2)
    {
      if ((tmp = malloc(sizeof(char) * (i + 2))) == NULL)
	return (NULL);
            while (++k < i)
	tmp[k] = str[k];
      tmp[k] = '\0';
    }
  else
    {
      i = -1;
      while (str[++i] != '\0');
      if ((tmp = malloc(sizeof(char) * (i + 2))) == NULL)
	return (NULL);
      i = -1;
      while (str[++i] != '\0')
	tmp[i] = str[i];
      tmp[i] = '\0';
    }
  return (tmp);
}

char		*new_tmp(char *tmp, size_t size, char *buffer)
{
  char		*str;
  int		i;
  int		k;

  i = 0;
  k = 0;
  while (tmp != NULL && tmp[i] != '\0')
    i++;
  if ((str = malloc(sizeof(char) * (i + size + 2))) == NULL)
    return (NULL);
  i = 0;
  while (tmp != NULL && tmp[i] != '\0')
    {
      str[i] = tmp[i];
      i++;
    }
  while (buffer[k] != '\0')
    str[i++] = buffer[k++];
  str[i] = '\0';
  if (tmp != NULL)
    tmp = NULL;
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	*tmp = NULL;
  char		*line;
  char		buffer[READ_SIZE + 1];
  static int	rd = 1;
  int		i;

  if (fd < 0)
    return (NULL);
  while ((i = find_str(tmp)) == -2)
    {
      if ((rd = read(fd, buffer, READ_SIZE)) < 0)
	return (NULL);
      if (rd == 0)
	exit(EXIT_SUCCESS);
      buffer[rd] = '\0';
      tmp = new_tmp(tmp, rd, buffer);
      if (rd == 0 && tmp[0] == '\0')
      	return (NULL);
    }
  line = find_line(tmp, i);
  tmp = &tmp[i + 1];
  return (line);
}
