NAME = so_long
SRC = so_long.c render_map.c read_map.c move.c utils.c key_hook.c validate.c path_checker.c display_mssg.c more_utils.c 
OBJ = $(SRC:.c=.o)
CC = gcc
fsanitizer = -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror $(fsanitizer)
MLX = ./mlx/
LIBFT = libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) all -C ./libft
	cp ./libft/$(LIBFT) ./
	$(MAKE) -C $(MLX)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)
	# $(MAKE) clean -C $(MLX)

fclean: clean
	$(MAKE) fclean -C ./libft/
	rm -f $(NAME)
	rm -rf $(LIBFT)

re: fclean all
