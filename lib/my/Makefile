##
## Makefile for Makefile in /home/vatout_a/rendu/Piscine_C_J10/lib/my
##
## Made by Vatoutine Artem
## Login   <vatout_a@epitech.net>
##
## Started on  Fri Oct  9 11:18:37 2015 Vatoutine Artem
## Last update Thu Jun  2 12:02:38 2016 andre
##

RM	=	rm -f

LIBC	=	ar rc

LIBR	=	ranlib

CP	=	cp

HEAD	=	-Iinclude

NAME	=	libmy.a

CFLAGS	=	-W -Wall -Wextra -ansi

SRCS	=	my_printf.c \
		my_va_conv_putstr.c \
		my_va_conv_adr.c \
		my_va_conv_bin.c \
		my_va_conv_hex.c \
		my_va_conv_nbr.c \
		my_memset.c \
		my_memset_int.c \
		my_epur_str.c \
		my_strcat.c \
		my_strcpy.c \
		my_strcmp.c \
		my_strlen.c \
		my_putchar.c \
		my_str_to_wordtab.c \
		my_put_nbr.c \
		my_putstr.c \
		my_putchar_error.c \
		my_putstr_error.c \
		my_tab_print.c \
		my_tab_free.c \
		my_tab_cpy.c \
		my_getnbr.c \
		my_cut_str.c \
		my_cut_until.c

OBJS	=	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBR) $(NAME)
	$(CP) $(NAME) ..

all:	$(NAME) clean

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
