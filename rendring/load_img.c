/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 05:26:17 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/09 22:12:23 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

static t_img	*load_img(t_data	*data, char	*filename)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
	{
		perror("Error\nInvalid Image");
		exit(1);
	}
	img->data = mlx_xpm_file_to_image(data->mlx, filename, \
		&img->x, &img->y);
	return (img);
}

void	load_imgs(t_data	*data)
{
	data->player_img = load_img(data, "./assets/player.xpm");
	data->collectable_img = load_img(data, "./assets/collectibles.xpm");
	data->house_img = load_img(data, "./assets/house.xpm");
	data->floor_img = load_img(data, "./assets/floor.xpm");
	data->wall_img = load_img(data, "./assets/wall.xpm");
}
