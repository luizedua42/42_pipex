NAME = pipex
CC = cc
CCFLAGS = -g3 -Wall -Werror -Wextra

OBJ = $(SRC:%.c=%.o)

SRC = pipex.c pipex_utils.c


%.o: %.c
	$(CC) $(CCFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ --no-print-directory
	$(CC) $(CCFLAGS) $(OBJ) libft/libft.a -o $(NAME)

bonus: $(NAMEBONUS)

clean:
	make -C libft/ clean --no-print-directory
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean --no-print-directory

re: fclean all

# $(NAMEBONUS) : $(BOBJ)
# $(CC) $(CCFLAGS) $(BOBJ) -o $(NAMEBONUS)
.PHONY: all bonus clean fclean re