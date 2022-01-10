/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:47:48 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/10 01:23:39 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_all(t_data	*map)
{
	int		i;

	i = 0;
	if (!map)
		return ;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map);
}
