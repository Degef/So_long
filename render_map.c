/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:34:12 by Degef             #+#    #+#             */
/*   Updated: 2023/04/15 16:17:02 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	render_map2(t_data *data, int x, int y)
{
	if (data->map->map[y / 32][x / 32] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img->w, x, y);
	else if (data->map->map[y / 32][x / 32] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img->c, x + 7, y + 7);
	else if (data->map->map[y / 32][x / 32] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img->e, x, y);
	else if (data->map->map[y / 32][x / 32] == 'P' && data->player_direction == RIGHT)
		mlx_put_image_to_window(data->mlx, data->win, data->img->p_right, x, y);
	else if (data->map->map[y / 32][x / 32] == 'P' && data->player_direction == LEFT)
		mlx_put_image_to_window(data->mlx, data->win, data->img->p_left, x, y);
	else if (data->map->map[y / 32][x / 32] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img->bg, x, y);
	else if (data->map->map[y / 32][x / 32] == '2' && data->enemy->dir)
		mlx_put_image_to_window(data->mlx, data->win, data->img->bullet_right, x, y);
	else if (data->map->map[y / 32][x / 32] == '2' && !data->enemy->dir)
		mlx_put_image_to_window(data->mlx, data->win, data->img->bullet_left, x, y);
	else {
		printf("%d, %d\n",x, y);
		handle_error(data, "Error! Wrong map entry detected\n", 1);
	}
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->size_y * IMG_W))
	{
		x = 0;
		while (x < (data->size_x * IMG_W))
		{
			render_map2(data, x, y);
			x += 32;
		}
		y += 32;
	}
}
