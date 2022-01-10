/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:44:43 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/09 21:51:34 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	img(t_data *data, t_img *img, int i, int j)
{
	mlx_put_image_to_window(data->mlx, \
		data->window, img->data, i * 36, j * 36);
}

void	put_img(t_data *data, int i, int j)
{
	char	c;

	c = data->map[j][i];
	if (c == 'P')
		img(data, data->player_img, i, j);
	else if (c == 'E')
		img(data, data->house_img, i, j);
	else if (c == '1')
		img(data, data->wall_img, i, j);
	else if (c == 'C')
		img(data, data->collectable_img, i, j);
}

int	move_player(int key, t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	if (key == ESC)
		exit (0);
	if (key == RIGHT)
		move_right(data);
	else if (key == LEFT)
		move_left(data);
	else if (key == UP)
		move_up(data);
	else if (key == RIGHT)
		move_right(data);
	else if (key == DOWN)
		move_down(data);
	rendring(data);
	return (0);
}

void	rendring(t_data	*data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			img(data, data->floor_img, i, j);
			put_img(data, i, j);
			i++;
		}
		j++;
	}
}
