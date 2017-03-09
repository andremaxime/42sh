/*
** get_next_line.h for GetNextLine in /home/darrig_s/PROG_ELEM/CPE_2015_getnextline
** 
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
** 
** Started on  Mon Jan  4 11:15:14 2016 Sophie Darrigol
** Last update Sun Jun  5 23:30:42 2016 RIMBAUD
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef READ_SIZE
#define READ_SIZE (120)
#endif /* !READ_SIZE */

int		find_str(char *str);
char		*find_line(char *str, int i);
char		*new_tmp(char *tmp, size_t size, char *buffer);
char		*get_next_line(const int fd);

#endif /*GET_NEXT_LINE*/
