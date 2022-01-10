/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:23:19 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/08 19:19:44 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

int	check_map_size(char *line)
{
	static int	len_line;
	int			i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!len_line)
		len_line = i;
	else
	{
		if (len_line != i)
		{
			return (-1);
		}
	}
	return (1);
}

int	check_first_last_width(char	*line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (-1);
		i++;
	}
	if (data)
		data->width = i;
	return (1);
}

int	check_mapneeds(t_data *data)
{
	int	h;
	int	w;
	int	p;
	int	e;

	h = -1;
	p = 0;
	data->collectibles = 0;
	e = 0;
	while (data->map[++h])
	{
		w = -1;
		while (data->map[h][++w] != '\n' && data->map[h][w])
		{
			if (data->map[h][w] == 'C')
				data->collectibles++;
			else if (data->map[h][w] == 'P')
				p++;
			else if (data->map[h][w] == 'E')
				e++;
			else if (data->map[h][w] != '1' && data->map[h][w] != '0')
				return (0);
		}
	}
	return (data->collectibles > 0 && p == 1 && e > 0);
}

int	check_first_last_height(char **map, int height)
{
	int	w;
	int	h;

	w = 0;
	h = -1;
	while (map[0][w] && map[0][w] != '\n')
		w++;
	while (++h < height)
		if (map[h][0] != '1')
			return (-1);
	h = -1;
	while (++h < height)
		if (map[h][w - 1] != '1')
			return (-1);
	if (map[height - 1][w] == '\n')
		return (-1);
	return (1);
}

void	check_map(t_data *data)
{
	int	h;

	h = 0;
	while (data->map[h])
	{
		if (check_map_size(data->map[h++]) == -1)
			invalid_map(data);
	}
	if (check_mapneeds(data) == 0)
		invalid_map(data);
	if (check_first_last_width(data->map[0], data) == -1
		|| check_first_last_width(data->map[data->height - 1], 0) == -1)
		invalid_map(data);
	if (check_first_last_height(data->map, data->height) == -1)
		invalid_map(data);
}
