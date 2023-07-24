/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:46:13 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 09:37:58 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_rectangle(t_map *map)
{
	size_t	first_line_length;
	int		i;

	if (!map)
		return (0);
	i = 0;
	first_line_length = ft_strlen((map->plan)[0]);
	while ((map->plan)[i])
	{
		if (ft_strlen((map->plan)[i]) != first_line_length)
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Map must be rectangle!", 2);
			return (0);
		}
		i++;
	}
	return (1);
}
