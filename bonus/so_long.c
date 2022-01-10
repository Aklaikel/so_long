/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 06:44:38 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/10 02:43:18 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

static void	check_ber(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (!ft_strncmp(file_name + len - 4, ".ber", 4))
	{
		printf("Error\nFile name must end with {.ber}\n");
		exit(0);
	}
}

static int	animation(t_data *data)
{
	rendring (data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		printf("args error");
		return (0);
	}
	data = malloc(sizeof(t_data));
	data->collectibles = 0;
	check_ber(av[1]);
	data->number_of_moves = 0;
	data->height = 0;
	data->map = parse_map(av[1], &(data->height));
	check_map(data);
	player_position(data);
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, \
		data->width * 36, (data->height + 1) * 36, "so_long");
	load_imgs(data);
	mlx_hook(data->window, 2, 1L, move_player, data);
	mlx_hook(data->window, 17, 1L, distroy, data);
	mlx_loop_hook(data->mlx, animation, data);
	mlx_loop(data->mlx);
}
