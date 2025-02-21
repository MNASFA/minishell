NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -lreadline
HEADER = minishell.h
SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all