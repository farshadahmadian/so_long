/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:53:29 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/14 21:07:07 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*copy_indexes(t_list *temp, char **map_plan, int *i)
{
	int	j;

	j = 0;
	while (!(((char *)(temp->content))[j] == '\n'
		|| ((char *)(temp->content))[j] == '\0'))
	{
		map_plan[*i][j] = ((char *)(temp->content))[j];
		j++;
	}
	return (map_plan[*i]);
}

char	**copy_rows(t_list *lines, char **map_plan)
{
	t_list	*temp;
	int		i;
	size_t	columns;

	i = 0;
	temp = lines;
	columns = ft_strlen((char *)(temp->content));
	while (temp)
	{
		map_plan[i] = ft_calloc(columns + 1, sizeof(char));
		if (!map_plan[i])
		{
			free_double_pointer(map_plan, i);
			return (NULL);
		}
		copy_indexes(temp, map_plan, &i);
		temp = temp->next;
		i++;
	}
	return (map_plan);
}

char	**copy_map(t_list *lines)
{
	char	**map_plan;
	int		rows;

	if (!lines)
		return (NULL);
	rows = ft_lstsize(lines);
	map_plan = (char **)ft_calloc(rows + 1, sizeof(char *));
	if (!map_plan)
		return (NULL);
	copy_rows(lines, map_plan);
	return (map_plan);
}

int	create_copy(t_map *map, t_list *lines, int map_fd)
{
	map->plan = copy_map(lines);
	if (!map->plan)
	{
		free_list(lines, free_line);
		close(map_fd);
		return (0);
	}
	return (1);
}
