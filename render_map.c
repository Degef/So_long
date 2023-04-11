/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:34:12 by Degef             #+#    #+#             */
/*   Updated: 2023/04/11 09:36:08 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_map2(t_data *data, int x, int y)
{
	if (data->map->map[y / 32][x / 32] == '1')
		put_wall(&x, &y, data);
	else if (data->map->map[y / 32][x / 32] == 'C')
		put_collectible(&x, &y, data);
	else if (data->map->map[y / 32][x / 32] == 'E')
		put_exit(&x, &y, data);
	else if (data->map->map[y / 32][x / 32] == 'P')
		put_player(&x, &y, data);
	else if (data->map->map[y / 32][x / 32] == '0')
		put_background(&x, &y, data);
	else
		handle_error(data, "Error! Wrong map entry detected\n", 1);
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
