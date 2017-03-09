##
## Makefile for  in /home/andre_c/systemeunix/PSU_2015_42sh
##
## Made by andre
## Login   <andre_c@epitech.net>
##
## Started on  Sun Jun  5 19:01:18 2016 andre
## Last update Sun Jun  5 23:16:19 2016 Sophie Darrigol
##

HEAD	= -Iinclude

CFLAGS	= $(HEAD) -W -Wextra -Wall -ansi -pedantic -Werror

CC	= gcc

RM	= rm -f

NAME	= 42sh

LIB	= -lmy -L./lib

SRCS	= src/main.c \
	src/minishell.c \
	src/parse/my_parse.c \
	src/parse/my_parse_src.c \
	src/parse/rough_command.c \
	src/error/error_sys.c \
	src/exec/my_exec.c \
	src/exec/get_exit.c \
	src/exec/check_exec.c \
	src/exec/check_launch_sysprog.c \
	src/env/get_env.c \
	src/env/delete_all.c \
	src/env/use_env.c \
	src/env/set_env.c \
	src/env/check_quote.c \
	src/tools//get_next_line.c \
	src/tools/list.c \
	src/tools/list_factory.c \
	src/tools/my_compare.c \
	src/echo/get_echo.c \
	src/echo/echo_tab.c \
	src/pwd/get_pwd.c \
	src/env/init_env.c \
	src/pipe/find_path.c \
	src/pipe/pipe.c \
	src/pipe/init_triple.c \
	src/save_cd/do.c \
	src/save_cd/get_cd.c \
	src/save_cd/put_pwdcd.c \
	src/save_cd/my_strcpy2.c \
	src/save_cd/recup_home.c \
	src/save_cd/test_home.c \
	src/save_cd/error_cd.c \
	src/pipe/error_pipe.c \
	src/display_prompt.c \
	src/redir/doubleet.c \
	src/redir/doubleou.c \
	src/redir/check_redir_op2.c \
	src/redir/check_redir_op.c \
	src/redir/my_str_to_worktab.c \
	src/redir/find_redir.c \

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

bis: fclean all
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re bis
