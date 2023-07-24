/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:55:48 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:26:07 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	remove_new_line(char *line)
{
	size_t	length;

	if (!line)
		return ;
	length = ft_strlen(line);
	if (line[length - 1] == '\n')
		line[length - 1] = '\0';
}

t_list	*read_map(int map_fd)
{
	char	*line;
	t_list	*new;
	t_list	*lines;

	lines = NULL;
	line = get_next_line(map_fd);
	if (!line)
	{
		close(map_fd);
		return (NULL);
	}
	while (line)
	{
		remove_new_line(line);
		new = ft_lstnew(line);
		ft_lstadd_back(&lines, new);
		line = get_next_line(map_fd);
	}
	return (lines);
}
