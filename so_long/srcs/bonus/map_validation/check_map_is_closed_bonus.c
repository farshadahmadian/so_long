/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_is_closed_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:16:06 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:26:53 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_map_is_not_closed(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Map is not surrounded by walls!", 2);
}

int	check_map_top_and_bottom_side(t_map *map, int top_or_bottom)
{
	int			x;
	const char	*side;

	if (!map)
		return (0);
	x = 0;
	if (top_or_bottom == 0)
		side = "top";
	else
		side = "bottom";
	while ((map->plan)[top_or_bottom][x])
	{
		if ((map->plan)[top_or_bottom][x] != WALL)
		{
			print_map_is_not_closed();
			return (0);
		}
		x++;
	}
	return (1);
}

int	check_map_left_and_right_side(t_map *map, int left_or_right)
{
	int			y;
	const char	*side;

	if (!map)
		return (0);
	y = 0;
	if (left_or_right == 0)
		side = "left";
	else
		side = "right";
	while (y < map->rows)
	{
		if ((map->plan)[y][left_or_right] != WALL)
		{
			print_map_is_not_closed();
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_map_is_closed(t_map *map)
{
	if (!check_map_top_and_bottom_side(map, 0))
		return (0);
	if (!check_map_top_and_bottom_side(map, (map->rows) - 1))
		return (0);
	if (!check_map_left_and_right_side(map, 0))
		return (0);
	if (!check_map_left_and_right_side(map, (map->columns) - 1))
		return (0);
	return (1);
}
