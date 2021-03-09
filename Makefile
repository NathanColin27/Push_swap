# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolin <ncolin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 10:35:48 by ncolin            #+#    #+#              #
#    Updated: 2021/03/09 10:45:10 by ncolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER_NAME = checker
PUSHSWAP_NAME = push_swap

CC = clang -g
CFLAGS = -Wall -Wextra -Werror -I include

CHECKER_SRCS =	$(wildcard shared/*/*.c) \
				$(wildcard checker_files/*.c)
PUSHSWAP_SRCS =	$(wildcard shared/*/*.c) \
				$(wildcard push_swap_files/*.c)

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
PUSHSWAP_OBJS = $(PUSHSWAP_SRCS:.c=.o)

LDFLAGS = -L libft
LDLIBS = -lft 

TICK = \342\234\224
RE = \342\231\272
TRASH = \360\237\227\221

all:				libft $(CHECKER_NAME) $(PUSHSWAP_NAME)

libft:
					@make -s -C libft

$(CHECKER_NAME):	$(CHECKER_OBJS) libft/libft.a
					$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LDFLAGS) $(LDLIBS) -o $(CHECKER_NAME)
					@echo "\033[32;1m\rChecker compiled ${TICK}          \033[0m"
$(PUSHSWAP_NAME):	$(PUSHSWAP_OBJS) libft/libft.a
					$(CC) $(CFLAGS) $(PUSHSWAP_OBJS) $(LDFLAGS) $(LDLIBS) -o $(PUSHSWAP_NAME)
					@echo "\033[32;1m\rPush_swap compiled ${TICK}          \033[0m"
					
clean_libft:
					@make -s -C libft clean

fclean_libft:
					@make -s -C libft fclean					

clean:
					rm -rf $(CHECKER_OBJS) $(PUSHSWAP_OBJS)
					@echo "\033[32;1m\rDirectory cleaned ${TRASH}          \033[0m"

fclean:				clean fclean_libft
					rm -rf $(CHECKER_OBJS) $(PUSHSWAP_OBJS)
					@echo "\033[32;1m\rDirectory fully cleaned ${TRASH} ${TRASH} ${TRASH}          \033[0m"
					
re:					fclean all

re_push_swap:		@echo "\033[32;1m\rProject recompiling ${RE}          \033[0m"
					clean $(CHECKER_NAME) $(PUSHSWAP_NAME)

.PHONY: all clean fclean re libft clean_libft fclean_libft
