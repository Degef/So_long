/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:32:10 by Degef             #+#    #+#             */
/*   Updated: 2023/04/17 14:00:34 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "./libft/libft.h"

# define IMG_W 32
# define UP 13
# define DOWN 1
# define RIGHT 124
# define LEFT 2

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
}				t_map;

typedef struct s_img
{
	void	*w;
	void	*bg;
	void	*p;
	void	*c;
	void	*e;
}				t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		p_x;
	int		p_y;
	int		counter;
	int		collected;
	int		collectables;
	t_map	*map;
	t_img	*img;
}				t_data;


void	read_map(char **argv, t_data *data);
void	find_x_and_y(char **argv, t_data *data);

//render map
void	render_map(t_data *data);
void	put_mssg(t_data *data);

//Move
void	collect_food(t_data *data, int x, int y);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
//Move 2
void	ft_move(t_data *data, int x, int y);

// key_hook
int		key_hook(int keycode, t_data *data);
void	exit_window(t_data *data);

//utils
void	ft_move(t_data *data, int x, int y);
void	free_double_pointer(t_data *data);
void	handle_error(t_data *data, char *str, int num);
int		exit_game(t_data *data);
void	check_exit(t_data *data);

//validate
void	check_map_border(t_data *data);
void	check_exit_and_player(t_data *data);
void	check_collectable(t_data *data);
void	validate_map(t_data *data);

//path checker
void	check_path(t_data *data);
void	check_path_of_collectables(t_data *data, int x, int y);
int		is_valid_path_e(t_data *data, int x, int y, char **visited);
int		is_valid_path_c(t_data *data, int x, int y, char **visited);

// display mssg
void	put_mssg(t_data *data);
void	display_count_to_window(t_data *data);

//more utils
void	import_images(t_data *data);
void	find_px_py(t_data *data);
void	free_double_p(char ***str);

#endif
