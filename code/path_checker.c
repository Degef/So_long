/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:50:48 by Degef             #+#    #+#             */
/*   Updated: 2023/04/17 13:59:59 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	is_valid_path_e(t_data *data, int x, int y, char **visited)
{
	int	up;
	int	down;
	int	right;
	int	left;

	if (y < 0 || y >= data->size_y || x < 0 || x >= data->size_x
		|| data->map->map[y][x] == '1' || visited[y][x] == '1' )
		return (0);
	if (data->map->map[y][x] == 'E')
		return (1);
	visited[y][x] = '1';
	up = is_valid_path_e(data, x, y - 1, visited);
	down = is_valid_path_e(data, x, y + 1, visited);
	right = is_valid_path_e(data, x + 1, y, visited);
	left = is_valid_path_e(data, x - 1, y, visited);
	if (up || down || left || right)
		return (1);
	else
		return (0);
}

int	is_valid_path_c(t_data *data, int x, int y, char **visited)
{
	int	up;
	int	down;
	int	right;
	int	left;

	if (y < 0 || y >= data->size_y || x < 0 || x >= data->size_x
		|| data->map->map[y][x] == '1' || visited[y][x] == '1'
		|| visited[y][x] == 'E' )
		return (0);
	if (data->map->map[y][x] == 'P')
		return (1);
	visited[y][x] = '1';
	up = is_valid_path_c(data, x, y - 1, visited);
	down = is_valid_path_c(data, x, y + 1, visited);
	right = is_valid_path_c(data, x + 1, y, visited);
	left = is_valid_path_c(data, x - 1, y, visited);
	if (up || down || left || right)
		return (1);
	else
		return (0);
}

static void	fill_visited(char ***visited, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		(*visited)[i] = ft_calloc (sizeof(char), (data->size_x + 1));
		while (data->map->map[i][j])
		{
			(*visited)[i][j] = data->map->map[i][j];
			j++;
		}
		(*visited)[i][j] = '\0';
		i++;
	}
}

void	check_path_of_collectables(t_data *data, int x, int y)
{
	char	**visited;

	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'C')
			{
				visited = malloc(sizeof(char *) * (data->size_y + 1));
				if (!visited)
					handle_error(data, "Error! allocation failure.\n", 1);
				visited[data->size_y] = 0;
				fill_visited(&visited, data);
				if (!is_valid_path_c(data, x, y, visited))
					handle_error(data, "Error! No path for collectable.\n", 1);
				free_double_p(&visited);
			}
			x++;
		}
		y++;
	}
}

void	check_path(t_data *data)
{
	char	**visited;
	int		x;
	int		y;

	x = 0;
	y = 0;
	find_px_py(data);
	visited = malloc(sizeof(char *) * (data->size_y + 1));
	if (!visited)
		handle_error(data, "Error! allocation failure.\n", 1);
	visited[data->size_y] = 0;
	fill_visited(&visited, data);
	if (!is_valid_path_e(data, data->p_x, data->p_y, visited))
	{
		free_double_p(&visited);
		handle_error(data, "Error! No valid path exists.\n", 1);
	}
	free_double_p(&visited);
	check_path_of_collectables(data, x, y);
}
