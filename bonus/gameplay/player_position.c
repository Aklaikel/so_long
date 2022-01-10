/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:31:35 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/10 01:24:03 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long_bonus.h"

void	player_position(t_data *data)
{
	int	h;
	int	w;
	int	found;

	found = 0;
	h = 0;
	while (data->map[h])
	{
		w = 0;
		while (data->map[h][w] != '\n' && data->map[h][w])
		{
			if (data->map[h][w] == 'P')
			{
				data->player.x = w;
				data->player.y = h;
				found = 1;
				break ;
			}
			w++;
		}
		h++;
		if (found)
			break ;
	}
}
