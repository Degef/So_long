NAME = so_long
SRC = so_long.c put_images.c render_map.c read_map.c move.c utils.c key_hook.c validate.c path_checker.c display_mssg.c
# main.c 
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FSANITIZER = -fsanitize=address -fno-omit-frame-pointer
MLX = ./mlx/
LIBFT = libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) all -C ./libft
	cp ./libft/$(LIBFT) ./
	$(MAKE) -C $(MLX)
	$(CC) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit $(FSANITIZER) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)
	# $(MAKE) clean -C $(MLX)

fclean: clean
	$(MAKE) fclean -C ./libft/
	rm -f $(NAME)
	rm -rf $(LIBFT)

re: fclean all
