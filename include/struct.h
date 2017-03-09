/*
** struct.h for struct.h in /home/vatout_a/rendu/PSU_2015_minishell2
**
** Made by Vatoutine
** Login   <vatout_a@epitech.net>
**
** Started on  Tue Mar 29 14:37:03 2016 Vatoutine
** Last update Tue Apr 12 18:42:58 2016 Vatoutine
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef	struct		s_funk
{
  char			*line;
  struct s_funk		*next;
  struct s_funk		*prev;
}			t_funk;

typedef struct		s_list
{
  int			length;
  struct s_funk		*first;
  struct s_funk		*last;
}			t_list;

#endif /* STRUCT_H_ */
