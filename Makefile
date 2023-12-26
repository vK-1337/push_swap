# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 08:40:39 by vda-conc          #+#    #+#              #
#    Updated: 2023/12/26 14:29:44 by vda-conc         ###   ########.fr        #
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

OBJS = $(SRC:.c=.o) ./libft/libft.a

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -g3
LDFLAGS = -L./libft -lft

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

./libft/libft.a: FORCE
	@$(MAKE) -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)
	@echo "	 			+---------------------+\n\
					|  $(YELLOW)  PUSH_SWAP $(GREEN)[OK]$(NC)   |\n\
					+---------------------+"


.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean
	make all

.PHONY: all clean fclean re sort FORCE
