# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 08:40:39 by vda-conc          #+#    #+#              #
#    Updated: 2023/12/27 09:50:37 by vda-conc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = sort.c \
			costs.c \
			index.c \
			moves.c \
			parsing.c \
			push_swap.c \
			costs_two.c \
			push_swap_utils.c \
			./lst/lst_utils.c \
			./lst/lst_utils_two.c \
			./lst/lst_utils_three.c \
			./lst/lst_utils_four.c \
			./lst/lst_utils_five.c \

BONUS_SRC =	sort.c \
						costs.c \
						index.c \
						moves.c \
						parsing.c \
						./checker_42/checker_utils.c \
						./checker_42/checker.c \
						./checker_42/get_next_line.c \
						./checker_42/get_next_line_utils.c \
						push_swap_utils.c \
						./lst/lst_utils.c \
						./lst/lst_utils_two.c \
						./lst/lst_utils_three.c \
						./lst/lst_utils_four.c \
						./lst/lst_utils_five.c \
						check_instructions.c \

OBJS = $(SRC:.c=.o) ./libft/libft.a

BONUS_OBJS = $(BONUS_SRC:.c=.o) ./libft/libft.a

NAME = push_swap

LIBFT = ./libft/libft.a

BONUS = checker

CFLAGS = -Wall -Werror -Wextra -g3
LDFLAGS = -L./libft -lft

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)
	@echo "	 			+---------------------+\n\
					|  $(YELLOW)  PUSH_SWAP $(GREEN)[OK]$(NC)   |\n\
					+---------------------+"

$(LIBFT):
	make -C ./libft

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(BONUS_OBJS) -o $(BONUS)
	@echo "	 			+---------------------+\n\
					|  $(YELLOW)   CHECKER  $(GREEN)[OK]$(NC)   |\n\
					+---------------------+"

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME) $(BONUS)

bonus: $(NAME) $(BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C ./libft fclean

re: fclean
	make all

.PHONY: all clean fclean re sort
