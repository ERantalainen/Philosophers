CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
SRCS = helpers.c input.c main.c philo_helpers.c input.c main.c philos.c death.c
OBJS = $(SRCS:.c=.o)
NAME = philo

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.SECONDARY: $(OBJS)

.PHONY: clean fclean all re