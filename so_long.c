/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 06:44:38 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/05 18:19:39 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
#include "get_next_line/get_next_line.h"

static void	check_ber(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (!ft_strncmp(file_name + len - 4, ".ber", 4))
	{
		printf("File name must end with {.ber}\n");
		exit(0);
	}
}
int main(int ac , char**av)
{
    if(ac != 2)
    {
        printf("args error");
        return (0);
    }
   t_data  *data;
   data = malloc(sizeof(t_data));
    check_ber(av[1]);
    data->map = parse_map(av[1], &(data->height));
    check_map(data);
    player_position(data);
    data->mlx = mlx_init();
    data->window = mlx_new_window(data->mlx,\
        data->width * 36, data->height * 36,"so_long");
    rendring(data);
}