/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:03:51 by Degef             #+#    #+#             */
/*   Updated: 2023/04/11 09:39:41 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_block(t_data *data, int num)
{
	char	temp;

	temp = data->map->map[data->p_y][data->p_x];
	if (num == UP && (data->p_y > 0) && temp == 'P')
		move_up(data);
	else if (num == DOWN && data->p_y > 0 && data->p_y < (data->size_y - 1)
		&& temp == 'P')
		move_down(data);
	else if (num == RIGHT && data->p_x < (data->size_x - 1) && temp == 'P')
		move_right(data);
	else if (num == LEFT && data->p_x > 0 && temp == 'P')
		move_left(data);
	return (0);
}

void	exit_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	ft_putstr_fd("\n\nTotal number of collectables: ", 1);
	ft_putnbr_fd(data->collected, 1);
	ft_putstr_fd("\nnumber of moves: ", 1);
	ft_putnbr_fd(data->counter, 1);
	ft_putstr_fd("\n\n", 1);
	free_double_pointer(data);
	exit(1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_window(data);
	else if (keycode == 13 || keycode == 126)
		check_block(data, UP);
	else if (keycode == 1 || keycode == 125)
		check_block(data, DOWN);
	else if (keycode == 2 || keycode == 124)
		check_block(data, RIGHT);
	else if (keycode == 0 || keycode == 123)
		check_block(data, LEFT);
	data->counter += 1;
	put_mssg(data);
	display_count_to_window(data);
	return (0);
}
