NAME = fract_ol

SRC = srcs/main.c srcs/event.c srcs/fractal.c

FLAGS = -Wall -Wextra -Werror

SRC2 = main.o event.o fractal.o

all: $(NAME)

%.o : %.c
	gcc -c -o $@ $^

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@make -C ./minilibx_macos all
	@cp ./minilibx_macos/libmlx.a ./lib
	@cp ./libft/libft.a ./lib
	gcc  $(FLAGS) -I ./include/  -L./lib  -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(SRC)


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean
	@make -C ./minilibx_macos clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
