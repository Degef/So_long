/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:56:26 by Degef             #+#    #+#             */
/*   Updated: 2023/04/05 17:28:44 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(int *x, int *y, t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "./images/wall.xpm",
			&data->map->x, &data->map->y);
	if (!data->img)
		handle_error(data, "Error! Image couldn't be found\n", 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img, *x, *y);
}

void	put_collectible(int *x, int *y, t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "./images/food.xpm",
			&data->map->x, &data->map->y);
	if (!data->img)
		handle_error(data, "Error! Image couldn't be found\n", 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img, *x, *y);
}

void	put_exit(int *x, int *y, t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "./images/exit.xpm",
			&data->map->x, &data->map->y);
	if (!data->img)
		handle_error(data, "Error! Image couldn't be found\n", 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img, *x, *y);
}

void	put_background(int *x, int *y, t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "./images/background.xpm",
			&data->map->x, &data->map->y);
	if (!data->img)
		handle_error(data, "Error! Image couldn't be found\n", 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img, *x, *y);
}

void	put_player(int *x, int *y, t_data *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx, "./images/pac_full.xpm",
			&data->map->x, &data->map->y);
	if (!data->img)
		handle_error(data, "Error! Image couldn't be found\n", 1);
	mlx_put_image_to_window(data->mlx, data->win, data->img, *x, *y);
	data->p_x = *x / 32;
	data->p_y = *y / 32;
}
