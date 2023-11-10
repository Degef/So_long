/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:01:07 by Degef             #+#    #+#             */
/*   Updated: 2023/04/15 16:19:45 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ft_move(t_data *data, int x, int y)
{
	data->map->map[data->p_y][data->p_x] = '0';
	if (y >= 0)
	{
		data->p_x = x;
		data->p_y = y;
		data->map->map[data->p_y][data->p_x] = 'P';
	}
	data->counter += 1;
	// render_map(data);
	if (y < 0)
	{
		if (data->collectables == data->collected)
			exit_window(data);
	}
	// data->counter += 1;
	// put_mssg(data);
	// display_count_to_window(data);
}

void	check_exit(t_data *data)
{
	if (data->collectables == data->collected)
		ft_move(data, -1, -1);
}

void	free_double_pointer(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
		i++;
	while (i >= 0)
		free(data->map->map[i--]);
	free(data->map->map);
}

void	handle_error(t_data *data, char *str, int num)
{
	if (num)
		free_double_pointer(data);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	exit_game(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
