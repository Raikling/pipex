SRCS = pipex.c pipex_utils.c pipex_utils_2.c pipex_utils_3.c
OBJ = $(SRCS:.c=.o) 
NAME = pipex
CC = cc
FLAGS = -Wall -Werror -Wextra -g
AR = ar rcs
RM = rm -rf
PRINTF_DIR = ft_printf
LIBFT_DIR = Libft
INCLUDES = -I${PRINTF_DIR} -I${LIBFT_DIR}
LIBS = -L${PRINTF_DIR} -lftprintf -L${LIBFT_DIR} -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(PRINTF_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INCLUDES) $(LIBS)

%.o: %.C
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re