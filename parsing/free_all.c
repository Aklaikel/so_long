/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:47:48 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/07 11:23:37 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_all(t_data	*map)
{
	t_data	*tmp;
	int		i;

	i = 0;
	if (!map)
		return ;
	while (map)
	{
		tmp[i] = map[i];
		i++;
		free(&tmp);
	}
	free(map);
}
