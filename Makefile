LIBFT = -L./libft/ -lft

FLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = gcc -g -I./header_file/

RM = rm -f

NAME = pipex

SRC = 	main.c parse_argument.c utils.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	-@echo "Compiling..."
	make -C ./libft
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(LIBFT)

clean:
	-@echo "Removing object files..."
	make clean -C ./libft
	$(RM) $(OBJ)

fclean : clean
	-@echo "Removing object files and executive file..."
	make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all
