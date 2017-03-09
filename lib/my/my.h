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

/*
** current program
*/

/*
** my lib
*/
int	my_printf(const char *src, ...);
int	my_va_conv_nbr(va_list ap);
int	my_va_conv_soct(va_list ap);
int	my_va_conv_putchar(va_list ap);
int	my_va_conv_putstr(va_list ap);
int	my_va_conv_ld(va_list ap);
int	my_va_conv_lld(va_list ap);
int	my_va_conv_long(va_list ap);
int	my_va_conv_hexmin(va_list ap);
int	my_va_conv_hexmaj(va_list ap);
int	my_va_conv_oct(va_list ap);
int	my_va_conv_bin(va_list ap);
int	my_va_conv_adr(va_list ap);
void	my_put_oct(unsigned int nb);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_putstr_error(char *src);
int	my_putchar_error(char z);
char	*my_memset(char *src, int size);
int	*my_memset_int(int *src, int size);
int	my_put_nbr(int nb);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_strcmp(char *dest, char *src);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_cut_until(char *src, char z);
char	*my_cut_str(char *src, char a, char b);
char	*my_revstr(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_epur_str(char *src);
char		**my_str_to_wordtab(char **tab, char *src, char z);
t_tab	*my_tab_size(t_tab *tab_size, char *src, char z);
int     my_tab_word_nbr(char *src, char z);
char	**my_tab_init(t_tab *tab_size, char **tab);
char    **my_tab_fill(char **tab, char *src, char z);
int	my_tab_print(char **tab);
int	my_tab_free(char **tab);
char   **my_tab_cpy(char **src, char **dest);
char	*my_cut_str(char *src, char a, char b);
char	*my_cut_until(char *src, char z);

#endif /* MY_H_ */
