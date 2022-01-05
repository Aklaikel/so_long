/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_derection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:08:03 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/04 13:09:08 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"
void	move_derection(t_data	*data,t_position p);
void	move_up(t_data *data)
{
	t_position	p;
	
	p.x = data->player.x;
	p.y = data->player.y - 1;
	move_derection(data,p);
}

void	move_down(t_data *data)
{
	t_position	p;
	
	p.x = data->player.x;
	p.y = data->player.y + 1;
	move_derection(data,p);
}

void	move_right(t_data *data)
{
	t_position	p;
	
	p.x = data->player.x + 1;
	p.y = data->player.y;
	move_derection(data,p);
}

void	move_left(t_data *data)
{
	t_position	p;
	
	p.x = data->player.x - 1;
	p.y = data->player.y;
	move_derection(data,p);
}

void	move_derection(t_data	*data,t_position p)
{
	char	c;

	if (p.x >= data->width || p.x < 0 || p.y >= data->height || p.y < 0)
		return ;
	c  = data->map[p.y][p.x];
	if (c == '1' || (c == 'E' && data->collectibles != 0))
		return ;
	if (c == '0' || c == 'C')
	{
		data->map[data->player.y][data->player.x] = '0';
		data->map[p.y][p.x] = 'P';
		if (c == 'C')
			data->collectibles--;
		data->player.x = p.x;
		data->player.y = p.y;
	}
	else
	{
		printf("You win\n");
		// free_all
		exit(0);
	}
}
