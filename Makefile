# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nathan <nathan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 10:35:48 by ncolin            #+#    #+#              #
#    Updated: 2021/03/29 23:47:47 by nathan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER_NAME = checker
PUSHSWAP_NAME = push_swap

OS = $(shell uname -s)
ifeq ($(OS), Linux)
	TICK = \342\234\224
	RE = \342\231\272
	TRASH = \360\237\227\221
else
	TICK = \xE2\x9C\x94
	RE = \xE2\x99\xBA
	TRASH = \xF0\x9F\x97\x91
endif

CC = clang -g
CFLAGS = -Wall -Wextra -Werror -I include -fsanitize=address -fno-omit-frame-pointer -O2

CHECKER_SRCS =	./src/shared/inst/rev_rot.c\
				./src/shared/inst/swap.c\
				./src/shared/inst/push.c\
				./src/shared/inst/rot.c\
				./src/shared/inst/instructions_utils.c\
				./src/shared/utlis/utils.c\
				./src/shared/stack/stack_parse.c\
				./src/shared/stack/stack_create.c\
				./src/checker_files/input.c\
				./src/checker_files/valid_sort.c\
				./src/checker_files/exec.c\
				./src/checker_files/main.c\

PUSHSWAP_SRCS =	./src/shared/inst/rev_rot.c\
				./src/shared/inst/swap.c\
				./src/shared/inst/push.c\
				./src/shared/inst/rot.c\
				./src/shared/inst/instructions_utils.c\
				./src/shared/utlis/utils.c\
				./src/shared/stack/stack_parse.c\
				./src/shared/stack/stack_create.c\
				./src/push_swap_files/utils2.c\
				./src/push_swap_files/solve_3.c\
				./src/push_swap_files/utils.c\
				./src/push_swap_files/process.c\
				./src/push_swap_files/find_move.c\
				./src/push_swap_files/median.c\
				./src/push_swap_files/solve.c\
				./src/push_swap_files/main.c\
				./src/push_swap_files/solve_6.c\

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
PUSHSWAP_OBJS = $(PUSHSWAP_SRCS:.c=.o)

LDFLAGS = -L libft
LDLIBS = -lft 

all:				libft $(CHECKER_NAME) $(PUSHSWAP_NAME)

libft:
					@make -s -C libft

$(CHECKER_NAME):	$(CHECKER_OBJS) libft/libft.a
					@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LDFLAGS) $(LDLIBS) -o $(CHECKER_NAME)
					@echo "\033[32;1m\rChecker compiled ${TICK}          \033[0m"

$(PUSHSWAP_NAME):	$(PUSHSWAP_OBJS) libft/libft.a
					@$(CC) $(CFLAGS) $(PUSHSWAP_OBJS) $(LDFLAGS) $(LDLIBS) -o $(PUSHSWAP_NAME)
					@echo "\033[32;1m\rPush_swap compiled ${TICK}          \033[0m"
					
clean_libft:
					@make -s -C libft clean

fclean_libft:
					@make -s -C libft fclean					

clean:
					@rm -rf $(CHECKER_OBJS) $(PUSHSWAP_OBJS)
					@echo "\033[32;1m\rDirectory cleaned ${TRASH}          \033[0m"

fclean:				clean fclean_libft
					@rm -rf $(CHECKER_NAME) $(PUSHSWAP_NAME)
					@echo "\033[32;1m\rDirectory fully cleaned ${TRASH} ${TRASH} ${TRASH}          \033[0m"
					
re:					fclean all

re_push_swap:		@echo "\033[32;1m\rProject recompiling ${RE}          \033[0m"
					clean $(CHECKER_NAME) $(PUSHSWAP_NAME)

.PHONY: all clean fclean re libft clean_libft fclean_libft
