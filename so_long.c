/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:41:49 by Degef             #+#    #+#             */
/*   Updated: 2023/04/17 12:10:14 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	init_map(t_data *data)
{
	data->mlx = mlx_init();
	import_images(data);
	if (!data->mlx)
	{
		perror("Error\nprogramm init failed\n");
		exit(EXIT_FAILURE);
	}
	data->map->x = 1;
	data->map->y = 1;
	data->counter = 0;
	data->collected = 0;
	data->player_direction = RIGHT;
	data->win = mlx_new_window(data->mlx, (data->size_x * IMG_W),
			(data->size_y * IMG_W + IMG_W), "So Long");
	render_map(data);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, 17, 0, exit_game, data);
}

void	check_filename(char *file_name)
{
	file_name = file_name + (ft_strlen(file_name) - 4);
	if (ft_strncmp(file_name, ".ber", 4))
	{
		write(2, "Error!, Wrong file extension", 28);
		exit(1);
	}
}

void move_enemy_horizontally(t_data *data, t_enemy *enemy) {
	if (data->enemy_counter && data->map->map[enemy->y][enemy->x + 1] == 'P' && enemy->dir)
		exit_window(data);
	else if (data->enemy_counter && data->map->map[enemy->y][enemy->x - 1] == 'P' && !enemy->dir)
		exit_window(data);
	if (data->enemy_counter && data->map->map[enemy->y][enemy->x + 1] == '0' && enemy->moves == 6 && enemy->dir)
	{
		data->map->map[enemy->y][enemy->x] = '0';
		enemy->x += 1;
		data->map->map[enemy->y][enemy->x] = '2';
		enemy->moves = 1;
	}
	else if (data->enemy_counter && data->map->map[enemy->y][enemy->x - 1] == '0' && enemy->moves == 6 && !enemy->dir)
	{
		data->map->map[enemy->y][enemy->x] = '0';
		enemy->x -= 1;
		data->map->map[enemy->y][enemy->x] = '2';
		enemy->moves = 1;
	}
	if (data->enemy_counter && data->map->map[enemy->y][enemy->x + 1] == '1' && enemy->dir)
		enemy->dir = 0;
	else if (data->enemy_counter && data->map->map[enemy->y][enemy->x - 1] == '1' && !enemy->dir)
		enemy->dir = 1;
}

int	main_loop(void *da)
{
	t_data	*data;

	data = (t_data *)da;

	render_map(data);
	display_count_to_window(data);
	t_enemy *temp;
	temp = data->enemy;
	while (temp)
	{
		move_enemy_horizontally(data, temp);
		temp->moves += 1;
		temp = temp->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	my_map;
	t_img	img;

	if (argc != 2)
	{
		if (argc < 2)
			write (2, "There should be one argument\n", 34);
		else
			write (2, "There should be only one argument\n", 34);
		exit(1);
	}
	check_filename(argv[1]);
	data.enemy = NULL;
	data.enemy_counter = 0;
	find_x_and_y(argv, &data);
	my_map.map = ft_calloc(sizeof(char *), (data.size_y + 1));
	data.map = &my_map;
	data.img = &img;
	read_map(argv, &data);
	validate_map(&data);
	check_path(&data);
	init_map(&data);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_loop(data.mlx);
	perror("Error\nloop failed\n");
	exit(EXIT_FAILURE);
}
