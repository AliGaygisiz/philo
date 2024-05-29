SRCS = ./philo.c ./src/dine.c ./src/init.c ./src/utils.c ./src/single_philo.c ./src/error_management.c ./src/utils_2.c
NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -lpthread #-fsanitize=thread -g
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

$(NAME): $(SRCS)
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@${RM} $(NAME)

fclean:
	@${RM} $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re 
