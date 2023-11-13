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

#include "includes/so_long.h"

void	import_images(t_data *data)
{
	data->img->w = mlx_xpm_file_to_image(data->mlx, "./images/walls.xpm", &data->map->x, &data->map->y);
	data->img->c = mlx_xpm_file_to_image(data->mlx,	"./images/heart_small.xpm", &data->map->x, &data->map->y);
	data->img->e = mlx_xpm_file_to_image(data->mlx, "./images/exit2.xpm", &data->map->x, &data->map->y);
	data->img->bg = mlx_xpm_file_to_image(data->mlx, "./images/background.xpm", &data->map->x, &data->map->y);
	data->img->p_left = mlx_xpm_file_to_image(data->mlx, "./images/Moana_left.xpm", &data->map->x, &data->map->y);
	data->img->p_right = mlx_xpm_file_to_image(data->mlx, "./images/Moana_right.xpm", &data->map->x, &data->map->y);
	data->img->bullet_right = mlx_xpm_file_to_image(data->mlx,	"./images/fire_right.xpm", &data->map->x, &data->map->y);
	data->img->bullet_left = mlx_xpm_file_to_image(data->mlx, "./images/fire_left.xpm", &data->map->x, &data->map->y);
	if (!data->img->w || !data->img->c || !data->img->e || !data->img->bg || \
		!data->img->p_left || !data->img->p_right || !data->img->bullet_right || !data->img->bullet_left)
		handle_error(data, "Error! Image couldn't be found\n", 1);
}

t_enemy	*lstlast(t_enemy *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
			if (data->map->map[y][x] == '2')
			{
				t_enemy	*enemy;
				enemy = malloc(sizeof(t_enemy));
				enemy->x = x;
				enemy->y = y;
				enemy->dir = 1;
				enemy->moves = 0;
				enemy->next = NULL;
				if (!data->enemy)
					data->enemy = enemy;
				else 
					lstlast(data->enemy)->next = enemy;
				data->enemy_counter++;
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
