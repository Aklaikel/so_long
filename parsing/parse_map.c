/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 05:34:16 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/07 09:55:00 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

t_node	*new_node(char *line)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->next = NULL;
	node->line = line;
	return (node);
}

void	push(t_node	**head,	t_node	*new)
{
	t_node	*tmp;

	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while ((tmp)->next)
		(tmp) = (tmp)->next;
	(tmp)->next = new;
}

void	pop(t_node **head)
{
	t_node	*tmp_node;

	if (!head || !*head)
		return ;
	tmp_node = (*head)->next;
	free(*head);
	(*head) = tmp_node;
}

void	_error(void)
{
	perror("Error\n");
	exit(0);
}

char	**parse_map(char *filename, int *height)
{
	int		i;
	char	*line;
	char	**map;
	t_node	*head;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		_error();
	head = NULL;
	line = get_next_line(fd);
	while (line)
	{
		push(&head, new_node(line));
		(*height)++;
		line = get_next_line(fd);
	}
	map = malloc(((*height) + 1) * sizeof(char *));
	i = -1;
	while (++i < (*height) && head)
	{
		map[i] = head->line;
		pop(&head);
	}
	return (close(fd), map[i] = NULL, map);
}
