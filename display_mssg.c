/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mssg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:32:53 by Degef             #+#    #+#             */
/*   Updated: 2023/04/11 09:44:53 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_mssg(t_data *data)
{
	if (data->counter > 0)
	{
		ft_putnbr_fd(data->counter, 1);
		ft_putstr_fd(" : Moves and ", 1);
		ft_putnbr_fd(data->collected, 1);
		ft_putstr_fd(" collectables\n", 1);
	}
}

void	display_count_to_window(t_data *data)
{
	char	*str1;
	int		i;
	int		x;
	int		y;
	char	*str2;

	i = 0;
	x = 0;
	y = (data->size_y * IMG_W) + 1;
	while (data->map->map[0][i])
	{
		x = i * IMG_W;
		put_background(&x, &y, data);
		i++;
	}
	str1 = ft_itoa(data->counter);
	str2 = ft_itoa(data->collected);
	str1 = ft_strjoin(str1, " : Moves  ");
	str2 = ft_strjoin(str2, " : Collectables");
	mlx_string_put(data->mlx, data->win, 0, (y + 18), 0xFFD500, str1);
	mlx_string_put(data->mlx, data->win, 75, (y + 18), 0x00FF00, str2);
	free(str1);
	free(str2);
}
