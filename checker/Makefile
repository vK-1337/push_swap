SRC = get_next_line_utils.c \
			get_next_line.c \
			checker.c \

OBJS = $(SRC:.c=.o) ../libft/libft.a

NAME = checker

CFLAGS = -Wall -Werror -Wextra -g3
LDFLAGS = -L../libft -lft

# colors
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

LIBFT: FORCE
	@$(MAKE) -C ../libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)
	@echo "	 			+---------------------+\n\
					|  $(YELLOW)     GNL $(GREEN)[OK]$(NC)      |\n\
					+---------------------+"
	@echo "	 			+---------------------+\n\
					|  $(YELLOW)   CHECKER $(GREEN)[OK]$(NC)    |\n\
					+---------------------+"


.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all: LIBFT $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ../libft fclean

re: fclean
	make all

.PHONY: all clean fclean re sort FORCE
