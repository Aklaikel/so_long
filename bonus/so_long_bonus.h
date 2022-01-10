/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 07:32:25 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/10 03:03:54 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include<unistd.h>
# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<fcntl.h>
# include <mlx.h>
# define ESC 53
# define RIGHT 2
# define LEFT 0
# define UP 13
# define DOWN 1
// get_next_line
# define BUFFER_SIZE 1024

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		check_newline(char *ret);
char	*ft_strdup(char *s1);
//parsing
typedef struct s_node
{
	char			*line;
	struct s_node	*next;
}	t_node;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_img
{
	void	*data;
	int		x;
	int		y;
}	t_img;

typedef struct s_data
{
	int			collectibles;
	char		**map;
	int			height;
	int			width;
	t_position	player;
	void		*mlx;
	void		*window;
	t_img		*player_img;
	t_img		*floor_img;
	t_img		*collectable_img;
	t_img		*wall_img;
	t_img		*opengate_img;
	t_img		*closegate_img;
	t_img		*enemy_img;
	int			number_of_moves;
}	t_data;

int		ft_strlen(char *s);
int		ft_strncmp( char *s1, char *s2, int n);
char	**parse_map(char *filename, int *height);
void	check_map(t_data *data);
void	player_position(t_data	*data);
// rendering
void	rendring(t_data	*data);
void	put_img(t_data *data, int i, int j);
void	img(t_data *data, t_img *img, int i, int j);
int		move_player(int key, t_data *data);
void	load_imgs(t_data	*data);
int		distroy(int n);
// derection
void	move_derection(t_data *data, t_position p);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	invalid_map(t_data	*data);
//free 
void	free_all(t_data	*map);
//bonus
char	*ft_itoa(int nb);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strlen(char *str);
void	you_lose(void);
void	you_win(void);
#endif