/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:44:43 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/10 02:59:29 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long_bonus.h"

void	img(t_data *data, t_img *img, int i, int j)
{
	mlx_put_image_to_window(data->mlx, \
		data->window, img->data, i * 36, j * 36);
}

void	put_img(t_data *data, int i, int j)
{
	char	c;
	int		random;

	random = rand();
	c = data->map[j][i];
	if (c == 'P')
		img(data, data->player_img, i, j);
	else if (c == '0')
		img(data, data->floor_img, i, j);
	else if (c == 'E')
	{		
		if (random % 3 == 0)
			img(data, data->closegate_img, i, j);
		else
			img(data, data->opengate_img, i, j);
	}
	else if (c == '1')
		img(data, data->wall_img, i, j);
	else if (c == 'C')
		img(data, data->collectable_img, i, j);
	else if (c == 'X')
		img(data, data->enemy_img, i, j);
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
	mlx_string_put(data->mlx, data->window, 0, 36 * data->height, \
		0xf3f3f3, ft_strjoin2("  Moves: ", ft_itoa(data->number_of_moves)));
}
