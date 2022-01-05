/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklaikel <aklaikel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 05:34:16 by aklaikel          #+#    #+#             */
/*   Updated: 2022/01/03 22:22:35 by aklaikel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../get_next_line/get_next_line.h"
#include"../so_long.h"


t_node *new_node(char *line)
{
	t_node *node = malloc(sizeof(t_node));
	node->next = NULL;
	node->line = line;
	return (node);
}

void    push(t_node **head, t_node *new)
{
	if (!*head)
	{
		*head = new;
		return ;
	}
	t_node *tmp = *head;
	while ((tmp)->next)
		(tmp) = (tmp)->next;
	(tmp)->next  = new;
}
void	pop(t_node **head)
{
	t_node *tmp_node;

	if (!head || !*head)
		return ;
	tmp_node = (*head)->next;
	free(*head);
	(*head) = tmp_node;
}

char **parse_map(char *filename, int *height)
{
	int		i;
	char	*line;

	i = 0;
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(0);
	}
	t_node *head=NULL;
	*height=0;
	while ((line = get_next_line(fd)))
	{
		push(&head, new_node(line));
		// if (line[0] != '1' || (line[strlen(line) - 2] != '1'))
		// {
		// 	printf("Your Map Isn't Surrounded By Walls");
		// 	exit(0);
		// }
		(*height)++;
	}
	close(fd);
	char **map = malloc(((*height) +1) * sizeof(char *));
	while (i < (*height)  && head)
	{
		map[i] = head->line;
		
		pop(&head);
		i++;
	}
	map[i]=NULL;
	return (map);
}