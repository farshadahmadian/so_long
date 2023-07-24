/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:50:06 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 18:00:52 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_duplicate(char **duplicate)
{
	int		y;

	if (!duplicate)
		return ;
	y = 0;
	while (duplicate[y])
	{
		ft_printf("%s\n", duplicate[y]);
		y++;
	}
}

char	**duplicate_map(t_map map)
{
	char	**copy;
	int		y;

	y = 0;
	copy = ft_calloc(map.rows + 1, sizeof(char *));
	while ((map.plan)[y])
	{
		copy[y] = ft_strdup((map.plan)[y]);
		y++;
	}
	return (copy);
}

void	check_next(t_map *map, int x, int y)
{	
	if (y < 0 || y > map->rows - 1 || x < 0 || x > map->columns - 1
		|| map->valid_path->map_dup[y][x] == ' '
		|| map->valid_path->map_dup[y][x] == WALL)
		return ;
	if (map->valid_path->map_dup[y][x] == COLLECTIBLE)
		(map->valid_path->collectible_left)--;
	if (map->valid_path->map_dup[y][x] == EXIT)
		map->valid_path->is_exit_reached = 1;
	map->valid_path->map_dup[y][x] = ' ';
	check_next(map, x, y + 1);
	check_next(map, x, y - 1);
	check_next(map, x + 1, y);
	check_next(map, x - 1, y);
}

void	print_valid_path_error(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("No valid path was found!", 2);
}

int	check_valid_path(t_map *map)
{
	t_valid_path	*valid_path;

	valid_path = ft_calloc(1, sizeof(t_valid_path));
	if (!valid_path)
		return (0);
	ft_bzero(valid_path, sizeof(t_valid_path));
	valid_path->collectible_left = map->collectible->length;
	valid_path->is_exit_reached = 0;
	valid_path->map_dup = duplicate_map(*map);
	map->valid_path = valid_path;
	check_next(map, map->player->x, map->player->y);
	if (valid_path->collectible_left == 0 && valid_path->is_exit_reached == 1)
		return (1);
	else if (valid_path->collectible_left > 0
		&& valid_path->is_exit_reached == 0)
		print_valid_path_error();
	else if (valid_path->collectible_left > 0)
		print_valid_path_error();
	else if (!valid_path->is_exit_reached)
		print_valid_path_error();
	return (0);
}
