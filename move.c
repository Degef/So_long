/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:29:09 by Degef             #+#    #+#             */
/*   Updated: 2023/04/15 14:24:13 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_food(t_data *data, int x, int y)
{
	data->collected++;
	ft_move(data, x, y);
}

void	move_up(t_data *data)
{
	if (data->map->map[data->p_y - 1][data->p_x] == '1')
		return ;
	else if (data->map->map[data->p_y - 1][data->p_x] == '0')
		ft_move(data, data->p_x, (data->p_y - 1));
	else if (data->map->map[data->p_y - 1][data->p_x] == 'C')
		collect_food(data, data->p_x, (data->p_y - 1));
	else if (data->map->map[data->p_y - 1][data->p_x] == 'E')
		check_exit(data);
}

void	move_down(t_data *data)
{
	if (data->map->map[data->p_y + 1][data->p_x] == '1')
		return ;
	else if (data->map->map[data->p_y + 1][data->p_x] == '0')
		ft_move(data, data->p_x, (data->p_y + 1));
	else if (data->map->map[data->p_y + 1][data->p_x] == 'C')
		collect_food(data, data->p_x, (data->p_y + 1));
	else if (data->map->map[data->p_y + 1][data->p_x] == 'E')
		check_exit(data);
}

void	move_right(t_data *data)
{
	if (data->map->map[data->p_y][data->p_x + 1] == '1')
		return ;
	else if (data->map->map[data->p_y][data->p_x + 1] == '0')
		ft_move(data, data->p_x + 1, data->p_y);
	else if (data->map->map[data->p_y][data->p_x + 1] == 'C')
		collect_food(data, data->p_x + 1, (data->p_y));
	else if (data->map->map[data->p_y][data->p_x + 1] == 'E')
		check_exit(data);
}

void	move_left(t_data *data)
{
	if (data->map->map[data->p_y][data->p_x - 1] == '1')
		return ;
	else if (data->map->map[data->p_y][data->p_x - 1] == '0')
		ft_move(data, data->p_x - 1, data->p_y);
	else if (data->map->map[data->p_y][data->p_x - 1] == 'C')
		collect_food(data, data->p_x - 1, (data->p_y));
	else if (data->map->map[data->p_y][data->p_x - 1] == 'E')
		check_exit(data);
}
