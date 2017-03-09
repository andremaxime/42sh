/*
** my.h for my.h in /home/vatout_a/lib/my
**
** Made by Vatoutine Artem
** Login   <vatout_a@epitech.net>
**
** Started on  Sun Nov 15 14:26:47 2015 Vatoutine Artem
** Last update	Tue Feb 23 19:57:30 2016 Vatoutine Artem
*/

#ifndef MY_H_
# define MY_H_

typedef	struct	s_tab
{
  int		words;
  int		*word;
}		t_tab;

# include <stdarg.h>
# include "struct.h"

/*
** current program
*/
char		*put_pwd(char *);
int		changepwd(char *, t_list *);
int		my_newprompt(char prompt[4096], char *);
char		*display_prompt(char *);
char		*recup_home(t_list *, char *);
char		*my_strcat2(char *, char *, int);
char		*my_strcpy2(char *);
int		get_cd(t_list *, char *);
t_list		*update_oldpwd(t_list *env, char *src);
t_list		*update_newpdw(t_list *env, char *src);
char		*save_oldpwd(char *oldpwd, t_list *env);
t_list		*teleport_to(t_list *env, char *pwd);
int		check_case(char *src);
int		get_env(t_list *, char *);
int		get_exit(t_list *, char *);
int		launch_case_norm(char *src, t_list *env, char *home);
int		launch_case_tir(char *src, t_list *env, char *home);
int		launch_case_tilde(char *src, t_list *env, char *home);
int		get_echo(t_list *, char *);
int		get_pwd(t_list *, char *);
void		init_echoflags(char *flags[1]);
void		init_echotab(int (*tab_flags[1])(char *));
int		init_env(t_list *);
int		multi_pipe(char ***, t_list *);
char		***init_triple(char *);
char		**create_path(char **);

/*
** cd
*/
int		do_cd3(char *, char **, char *);
int		test_home(char *);
int		test_home_cd(char *);
int		check_cd(char **);
int		check_debut(char *, char *);
int		display_error_cd(char *);

/*
** parse
*/
char		**my_parse(char **path, t_list *env, char *src);
int		parse_rough_command(char *src);
int		my_parse_src(t_list *env, char *src);
int		load_double_dot(t_list *env, char ***source, char *src);

/*
** exec
*/
int		my_check_access(char **tmp);
char		**concat_command(char **path, char **tmp, char *command);
char		**tab_realloc(char **tmp, t_tab *tab_size, char *command);
char		**check_exec(char **path, char **command);
int		check_prog_or_user(char **command, char **tmp);
int		check_launch_sysprog(char **path, t_list *env, char *src);

/*
** env
*/
char		**my_list_to_tab(char **envp, t_list *env);
t_list		*my_env_to_list(t_list *env, char **envp);
char		*my_parse_list_env(t_list *env, char *var);
char		*my_parse_tab_env(t_list *env, char *src);
t_funk		*find_elem(t_list *env, char *src);
int		go_env(t_list *env, char *src);
int		unset_env(t_list *env, char *var);
int		set_env(t_list *env, char *var, char *content);
void		delete_all(t_list *);
int		my_quote_check(char *);
char		*remove_quotes(char *);

/*
** else
*/
int		my_algo_2(t_list *env, char *src);
int		my_algo(t_list *env);
int		my_compare(char *src, char *dest);
int		check_letter(char *src);
char		**my_list_to_tab(char **envp, t_list *env);
char		**my_str_to_wordtab2(char *, char);
void		my_free_list(t_list *env);
t_list		*my_init_list(t_list *env);
t_list		*delete_elem(t_list *env, t_funk *funk);
t_list		*add_elem_content(t_list *env, t_funk *funk, char *src);
t_list		*add_elem(t_list *env, char *src);
int		my_list_print(t_list *env);
int		error_sys(int error, char *src);
int		special_n();
int		my_aout_exec(char **tab, char **envp);
int		my_exec(char **tmp, char **tab, char **envp, int res);
t_tab		*my_tab_length(char **tab, t_tab *tab_size);
int		minishell(char **envp);

/*
** my lib
*/
int		my_printf(const char *src, ...);
int		my_va_conv_nbr(va_list ap);
int		my_va_conv_soct(va_list ap);
int		my_va_conv_putchar(va_list ap);
int		my_va_conv_putstr(va_list ap);
int		my_va_conv_ld(va_list ap);
int		my_va_conv_lld(va_list ap);
int		my_va_conv_long(va_list ap);
int		my_va_conv_hexmin(va_list ap);
int		my_va_conv_hexmaj(va_list ap);
int		my_va_conv_oct(va_list ap);
int		my_va_conv_bin(va_list ap);
int		my_va_conv_adr(va_list ap);
void		my_put_oct(unsigned int nb);
int		my_putchar(char c);
int		my_putstr(char *str);
int		my_putstr_error(char *src);
int		my_putchar_error(char z);
char		*my_memset(char *src, int size);
int		*my_memset_int(int *src, int size);
int		my_put_nbr(int nb);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		my_strcmp(char *dest, char *src);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int nb);
char		*my_cut_until(char *src, char z);
char		*my_cut_str(char *src, char a, char b);
char		*my_revstr(char *str);
char		*my_strcat(char *dest, char *src);
char		*my_epur_str(char *src);
char		**my_str_to_wordtab(char **tab, char *src, char z);
t_tab		*my_tab_size(t_tab *tab_size, char *src, char z);
int		my_tab_word_nbr(char *src, char z);
char		**my_tab_init(t_tab *tab_size, char **tab);
char		**my_tab_fill(char **tab, char *src, char z);
int		my_tab_print(char **tab);
int		my_tab_free(char **tab);
char		**my_tab_cpy(char **src, char **dest);
char		*my_cut_str(char *src, char, char b);
char		*my_cut_until(char *, char);

/*
** redir
*/
char	**my_str_to_worktab(char *str, int, int);
int	doubleet(t_list *list, char **t_exec);
int	doubleou(t_list *list, char **t_exec);
int	find_redir(char *str, char *to_find);
char	**cut_str(char *, char **, int);
int	check_tab(char *src, t_list *envp);
int	check_redir_op(char *src);

#endif /* MY_H_ */
