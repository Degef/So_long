/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:46:59 by Degef             #+#    #+#             */
/*   Updated: 2023/04/17 12:31:32 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	import_images(t_data *data)
{
	data->img->w = mlx_xpm_file_to_image(data->mlx, "./images/wall.xpm",
			&data->map->x, &data->map->y);
	if (!data->img->w)
		handle_error(data, "Error! Image couldn't be found\n", 1);
	data->img->c = mlx_xpm_file_to_image(data->mlx,
			"./images/collectable.xpm", &data->map->x, &data->map->y);
	if (!data->img->c)
		handle_error(data, "Error! Image couldn't be found\n", 1);
	data->img->e = mlx_xpm_file_to_image(data->mlx, "./images/exit.xpm",
			&data->map->x, &data->map->y);
	if (!data->img->e)
		handle_error(data, "Error! Image couldn't be found\n", 1);
	data->img->bg = mlx_xpm_file_to_image(data->mlx,
			"./images/background.xpm", &data->map->x, &data->map->y);
	if (!data->img->bg)
		handle_error(data, "Error! Image couldn't be found\n", 1);
	data->img->p = mlx_xpm_file_to_image(data->mlx,
			"./images/pac_full.xpm", &data->map->x, &data->map->y);
	if (!data->img->p)
		handle_error(data, "Error! Image couldn't be found\n", 1);
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

void	free_double_p(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
		i++;
	i--;
	while (i >= 0)
		free((*str)[i--]);
	free((*str));
}
