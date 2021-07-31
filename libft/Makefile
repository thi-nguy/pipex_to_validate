NAME = libft.a

CC = gcc -c -g

AR = ar rc

FLAGS = -Wall -Wextra -Werror

SRC = ft_split.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_bzero.c\
			ft_strdup.c ft_strncmp.c free_array.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
