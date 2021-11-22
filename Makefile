NAME = philo
FLAGS = -Wall -Werror -Wextra
SRC = philo.c utils_1.c utils.c
LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -s -C libft/

$(NAME): $(LIBFT)
	gcc $(SRC) $(LIBFT) $(FLAGS) -o $(NAME)

clean:
	$(MAKE) -s -C libft/ fclean

fclean: clean
	rm -f $(NAME)

re:	fclean all