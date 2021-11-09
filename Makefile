
all:
	@$(MAKE) -s -C libft/
	@gcc libft/libft.a philo.c