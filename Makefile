# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vda-conc <vda-conc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 08:40:39 by vda-conc          #+#    #+#              #
#    Updated: 2023/12/09 19:24:46 by vda-conc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c

OBJS = $(SRC:.c=.o) 

SORT_OBJS = $(SORT:.c=.o)

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L./libft -lft

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

./libft/libft.a: FORCE
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) ./libft/libft.a
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