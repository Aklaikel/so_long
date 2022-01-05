/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:17:12 by aklaikel          #+#    #+#             */
/*   Updated: 2021/12/28 16:18:59 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# define BUFFER_SIZE 1024

char	*get_next_line(int fd);
int	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		check_newline(char *ret);
char	*ft_strdup(char *s1);

#endif
