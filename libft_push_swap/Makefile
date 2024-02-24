# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 15:00:12 by cyferrei          #+#    #+#              #
#    Updated: 2024/02/19 16:14:02 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_strstr.c \
		print_char.c \
		print_hexa.c \
		print_int.c \
		print_percent.c \
		print_pointer.c \
		print_string.c \
		print_unsigned.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_itoa.c \
		ft_calloc.c \
		ft_bzero.c \
		ft_split.c \
		ft_atoi.c \
		ft_lstadd_back.c \
		ft_lstnew.c \
		ft_lstlast.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstsize.c \
		ft_strcmp.c \
		ft_strdup.c
		
NAME = libft_push_swap.a
OBJS = $(SRC:.c=.o)
CC = cc
RM = rm -rf
AR = ar rcs
FLAGS = -Wall -Wextra -Werror
HEADER_FILE = libft_push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_FILE)
		$(AR) $(NAME) $(OBJS)
		ranlib $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -o $@ -c $<

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re