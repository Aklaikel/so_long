/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:27:54 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/09 22:10:05 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	invalid_map(t_data	*data)
{
	printf("Eroor\nInvalid Map\n");
	free_all(data);
	exit(0);
}
