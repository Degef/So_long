/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:17:35 by Degef             #+#    #+#             */
/*   Updated: 2023/04/11 09:12:13 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_border2(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
	{
		if (data->map->map[i][0] != '1')
			handle_error(data,
				"Error! Left side borders are not all blocks\n", 1);
		i++;
	}
	i = 0;
	while (data->map->map[i])
	{
		if (data->map->map[i][data->size_x - 1] != '1')
			handle_error(data,
				"Error! Right side borders are not all blocks\n", 1);
		i++;
	}
}

void	check_map_border(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[0][i])
	{
		if (data->map->map[0][i] != '1')
			handle_error(data, "Error! Top borders are not all blocks\n", 1);
		i++;
	}
	i = 0;
	while (data->map->map[data->size_y - 1][i])
	{
		if (data->map->map[data->size_y - 1][i] != '1')
			handle_error(data, "Error! Bottom borders are not all blocks\n", 1);
		i++;
	}
	check_map_border2(data);
}

void	check_exit_and_player(t_data *data)
{
	int	i;
	int	j;
	int	e;
	int	p;

	i = 0;
	p = 0;
	e = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'E')
				e++;
			else if (data->map->map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (e > 1 || p > 1)
		handle_error(data, "Error! More than one players or exit detected\n", 1);
}

void	check_collectable(t_data *data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c < 1)
		handle_error(data, "Error! You don't have any collectable\n", 1);
}

void	validate_map(t_data *data)
{
	check_map_border(data);
	check_exit_and_player(data);
	check_collectable(data);
}
