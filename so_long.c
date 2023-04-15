/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:41:49 by Degef             #+#    #+#             */
/*   Updated: 2023/04/15 16:05:35 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		perror("Error\nprogramm init failed\n");
		exit(EXIT_FAILURE);
	}
	data->map->x = 1;
	data->map->y = 1;
	data->counter = 0;
	data->collected = 0;
	data->win = mlx_new_window(data->mlx, (data->size_x * IMG_W),
			(data->size_y * IMG_W + IMG_W), "So Long");
	import_images(data);
	render_map(data);
	mlx_key_hook(data->win, key_hook, data);
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

void	find_px_py(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'P')
			{
				data->p_x = x;
				data->p_y = y;
			}
			x++;
		}
	y++;
	}
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
	find_x_and_y(argv, &data);
	my_map.map = malloc(sizeof(char *) * (data.size_y + 1));
	data.map = &my_map;
	data.img = &img;
	read_map(argv, &data);
	validate_map(&data);
	check_path(&data);
	init_map(&data);
	mlx_loop(data.mlx);
	perror("Error\nloop failed\n");
	exit(EXIT_FAILURE);
}
