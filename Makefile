# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 13:32:46 by aridolfi          #+#    #+#              #
#    Updated: 2016/12/14 14:07:41 by aridolfi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME	= libftprintf.a

# Compilation
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# Directories
LIBDIR	= libft
PFDIR	= printf
OBJDIR	= objs

# SRCS & OBJT
SRCS 	=	libft/ft_atoi.c				\
			libft/ft_bzero.c			\
			libft/ft_digitcount.c		\
			libft/ft_int_tab_bubble.c	\
 			libft/ft_isalnum.c 			\
			libft/ft_isalpha.c			\
			libft/ft_isascii.c			\
			libft/ft_isdigit.c			\
			libft/ft_isprint.c			\
			libft/ft_iswhitespace.c		\
			libft/ft_itoa.c				\
			libft/ft_lstadd.c			\
			libft/ft_lstback.c			\
			libft/ft_lstdel.c			\
			libft/ft_lstdelone.c		\
			libft/ft_lstiter.c			\
			libft/ft_lstmap.c			\
			libft/ft_lstnew.c			\
			libft/ft_memalloc.c			\
			libft/ft_memccpy.c			\
			libft/ft_memchr.c			\
			libft/ft_memcmp.c			\
			libft/ft_memcpy.c			\
			libft/ft_memdel.c			\
			libft/ft_memmove.c			\
			libft/ft_memset.c			\
			libft/ft_memswap.c			\
			libft/ft_putchar_fd.c		\
			libft/ft_putchar.c			\
			libft/ft_putendl_fd.c		\
			libft/ft_putendl.c			\
			libft/ft_putnbr_fd.c		\
			libft/ft_putnbr.c			\
			libft/ft_putstr_fd.c		\
			libft/ft_putstr.c			\
			libft/ft_strcat.c			\
			libft/ft_strchr.c			\
			libft/ft_strclr.c			\
			libft/ft_strcmp.c			\
			libft/ft_strcpy.c			\
			libft/ft_strdel.c			\
			libft/ft_strdup.c			\
			libft/ft_strequ.c			\
			libft/ft_strfind.c			\
			libft/ft_striter.c			\
			libft/ft_striteri.c			\
			libft/ft_strjoin.c			\
			libft/ft_strlcat.c			\
			libft/ft_strlen.c			\
			libft/ft_strmap.c			\
			libft/ft_strmapi.c			\
			libft/ft_strncat.c			\
			libft/ft_strncmp.c			\
			libft/ft_strncpy.c			\
			libft/ft_strnequ.c			\
			libft/ft_strnew.c			\
			libft/ft_strnstr.c			\
			libft/ft_strsplit.c			\
			libft/ft_strrchr.c			\
			libft/ft_strstr.c			\
			libft/ft_strsub.c			\
			libft/ft_strtrim.c			\
			libft/ft_tolower.c			\
			libft/ft_toupper.c			\
			libft/get_next_line.c		\
			\
			printf/ft_printf.c

OBJT	= $(SRCS:.c=.o)

# **************************************************************************** #

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# Bonus

.PHONY:		all clean fclean re

# **************************************************************************** #

# Rules

all: $(NAME)

$(NAME): $(OBJT)
	@ar rc $(NAME) $(OBJT)
	@ranlib $(NAME)

%.o: %.c
	@echo "--$(LOG_CLEAR)$(LOG_GREEN)$(NAME)$(LOG_NOCOLOR) ........................ $(LOG_VIOLET)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^

clean:
	@rm -f $(OBJT)

fclean: clean
	@rm -f $(NAME)

re: fclean all
