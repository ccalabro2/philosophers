NAME = philo

SRCS = my_atois_and_checks.c monitor.c take_time.c philo_routine_and_check.c init_structs.c init_forks.c main.c \
		thread_init.c destroy_forks.c

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)

				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: 	$(NAME)

clean:
				$(RM) $(OBJS)

fclean: clean
				$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
