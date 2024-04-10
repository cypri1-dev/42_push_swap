# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 16:41:41 by cyferrei          #+#    #+#              #
#    Updated: 2024/03/11 21:34:38 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT_PUSH_SWAP_PATH = libft_push_swap/
LIBFT_PUSH_SWAP = libft_push_swap/libft_push_swap.a

BOLD    = \e[1m
FADE    = \e[2m
ITA     = \e[3m
BLINK   = \e[5m
GREEN   = \e[38;5;76m
RED     = \e[38;5;196m
YELLOW  = \e[38;5;227m
ORANGE  = \e[38;5;208m
PURPLE  = \e[38;5;201m
LBLUE   = \e[38;5;45m
BLUE    = \e[38;5;27m
INDI    = \e[38;5;91m
SPINK   = \e[38;5;225m
PEACH   = \e[38;5;223m
GREY    = \e[38;5;254m
RESET   = \e[00m

SOURCE = ./sources/

EXECUTION = $(addprefix exec/, exec_instructions.c exec_final_sort.c)
INSTRUCTIONS = $(addprefix instructions/, instructions_utils.c swap.c push.c rotate.c reverse_rotate.c)
ALGO = $(addprefix algorithm/, algo_utils.c algo.c algo_utils_2.c)
PUSH_SWAP = $(addprefix $(SOURCE), $(INSTRUCTIONS) $(ALGO) $(EXECUTION) push_swap.c parsing_args.c end_sort.c init.c init_utils.c)
CHECKER = $(addprefix checker/, checker.c checker_utils.c)
PUSH_SWAP_BONUS = $(addprefix $(SOURCE), $(INSTRUCTIONS) $(ALGO) $(EXECUTION) $(CHECKER) parsing_args.c end_sort.c init.c init_utils.c)

SRC_BONUS = $(PUSH_SWAP_BONUS)
SRC = $(PUSH_SWAP)
OBJS = $(SRC:%.c=%.o)
OBJS_BONUS = $(SRC_BONUS:%.c=%.o)

CMP = 1

all: $(NAME)

$(NAME): $(OBJS)
	@make -sC $(LIBFT_PUSH_SWAP_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PUSH_SWAP) -o $(NAME) 
	@printf "\n$(BOLD)$(BLUE)[OK]$(RESET) Compilation completed successfully\n"

$(NAME_BONUS): $(OBJS_BONUS)
	@make -sC $(LIBFT_PUSH_SWAP_PATH)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_PUSH_SWAP) -o $(NAME_BONUS)
	@printf "$(BOLD)$(BLUE)[OK]$(RESET) Bonus Compilation completed successfully\n" 
	
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null && printf "$(BOLD)$(GREEN)[OK]$(RESET) Compiled: $<\n"
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make -s clean -C $(LIBFT_PUSH_SWAP_PATH)
	@printf "$(BOLD)$(BLUE)[OK]$(RESET) Clean completed successfully\n"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make -s fclean -C $(LIBFT_PUSH_SWAP_PATH)
	@printf "$(BOLD)$(BLUE)[OK]$(RESET) Full clean completed successfully\n"

re: fclean all
	@printf "$(BOLD)$(BLUE)[OK]$(RESET) Recompilation completed successfully\n"

bonus: $(NAME_BONUS)
	
.PHONY: all clean fclean re
