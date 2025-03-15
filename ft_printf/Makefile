SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c \
	ft_putptr.c ft_putnbr_unsigned.c ft_printf.c
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIB = ar rcs
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${LIB} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${FLAGS} -c  $< -o $@

clean:
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re