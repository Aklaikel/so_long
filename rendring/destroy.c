/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 05:20:04 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/07 08:20:14 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	l_distroy(t_data	*data)
{
	mlx_destroy_window(data->mlx, data->window);
	exit(0);
}

int	distroy(int n, t_data	*data)
{
	l_distroy(data);
	return (n);
}
