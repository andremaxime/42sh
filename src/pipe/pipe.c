/*
** pipe.c for  in /home/maison_f/Epitech/rendu/PSU_2015_42sh/minishell2/pipe
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Thu Jun  2 21:27:58 2016 Maisonnave Florian
** Last update Sun Jun  5 23:20:27 2016 RIMBAUD
*/

#include "pipe.h"
#include "struct.h"
#include "my.h"

char		*my_access_strcat(char *s1, char *s2)
{
  char		*res;
  int		i;
  int		k;

  i = 0;
  k = 0;
  if ((res = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2)))
      == NULL)
    return (NULL);
  while (s1[i])
    {
      res[i] = s1[i];
      i++;
    }
  res[i] = '/';
  i++;
  while (s2[k])
    {
      res[i] = s2[k];
      i++;
      k++;
    }
  res[i] = 0;
  return (res);
}

char		*access_pipe(char **path, char *cmd)
{
  char		*way;
  int		i;

  i = 0;
  while (path[i] != NULL)
    {
      way = my_access_strcat(path[i], cmd);
      if ((access(way, F_OK)) == 0)
	return (way);
      free(way);
      i++;
    }
  return (NULL);
}

char		*exec_pipe_end(char *way, char ***cmd, int *pipefd, char **path)
{
   if (*(cmd + 1) != NULL)
    dup2(pipefd[1], 1);
  close(pipefd[0]);
  if ((way = access_pipe(path, (*cmd)[0])) == NULL)
    return (NULL);
  return (way);
}

char		*exec_pipe(t_pipe *p, char ***cmd, char **path, char **env)
{
  while (*cmd != NULL)
    {
      pipe(p->pipefd);
      if ((p->pid = fork()) == -1)
	return (NULL);
      else if (p->pid == 0)
        {
          dup2(p->fd, 0);
	  if ((p->way = exec_pipe_end(p->way, cmd, p->pipefd, path)) == NULL)
	    return (error_pipe(p, cmd));
	  if ((execve(p->way, *cmd, env)) == 0)
	    dup2(0, p->fd);
	  free(p->way);
        }
      else
        {
          waitpid(p->pid, &p->state, 0);
	  if (p->state == 139)
	    write(2, "Segmentation fault\n", 19);
          close(p->pipefd[1]);
	  p->fd = p->pipefd[0];
	  cmd++;
        }
    }
  return (NULL);
}

int		multi_pipe(char ***cmd, t_list *list)
{
  t_pipe	pipe;
  char		**env;
  char		**path;
  char		*error;

  env = NULL;
  if ((env = my_list_to_tab(env, list)) == NULL)
    return (0);
  if ((path = create_path(env)) == NULL)
    return (-1);
  if ((error = exec_pipe(&pipe, cmd, path, env)) != NULL)
    {
      write(2, error, my_strlen(error));
      write(2, ": Command not found.\n", 21);
      return (-1);
    }
  my_tab_free(path);
  return (0);
}
