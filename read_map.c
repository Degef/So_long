/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <Degei411233@outlook.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:39:29 by Degef             #+#    #+#             */
/*   Updated: 2023/04/17 12:13:10 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char **argv, t_data *data)
{
	int		i;
	int		fd;
	char	*str_inside;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	if (!(data->map->map))
		return ;
	while (i <= (data)->size_y)
	{
		str_inside = (char *)malloc(sizeof(char) * ((data)->size_x + 1));
		if (!str_inside)
			return ;
		read(fd, str_inside, data->size_x + 1);
		str_inside[(data)->size_x] = '\0';
		data->map->map[i - 1] = str_inside;
		i++;
	}
	data->map->map[i - 1] = 0;
}

static void	check_error(int x, int y, int sum, t_data *data)
{
	if ((x * (y - 1)) != sum)
		handle_error(data, "Map is not rectangle\n", 0);
	data->size_x = x;
	data->size_y = y;
}

static void	read_wid(int rd_byt, char **buff, int fd, t_data *data)
{
	int	x;
	int	y;
	int	sum;

	x = 0;
	y = 1;
	sum = 0;
	while (rd_byt == 1)
	{
		rd_byt = read(fd, (*buff), 1);
		if (rd_byt != 1)
			break ;
		else if (rd_byt && ((*buff)[0] != '\n'))
			x++;
		else if (rd_byt && ((*buff)[0] == '\n'))
		{
			y++;
			sum += x;
			x = 0;
		}
	}
	free(*buff);
	check_error(x, y, sum, data);
}

void	find_x_and_y(char **argv, t_data *data)
{
	int		fd;
	char	*buff;
	int		rd_bytes;

	buff = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		handle_error(data,
			"Error! File doesn't exist in the provided path\n", 0);
	rd_bytes = 1;
	buff = (char *)malloc (sizeof(char) * 2);
	if (!buff)
		exit(1);
	read_wid(rd_bytes, &buff, fd, data);
}
