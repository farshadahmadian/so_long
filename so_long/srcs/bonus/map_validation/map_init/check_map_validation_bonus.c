/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validation_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:45:51 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:25:58 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	initialize_map(t_map *map, const char *map_dir)
{
	get_map_size(map);
	if (!check_file_extension(map_dir, "ber"))
		return (0);
	if (!check_components(map))
		return (0);
	if (!check_map_rectangle(map))
		return (0);
	if (!check_map_is_closed(map))
		return (0);
	if (!set_map_player(map))
		return (0);
	if (!set_map_collectible(map))
		return (0);
	if (!set_map_exit(map))
		return (0);
	if (!check_valid_path(map))
		return (0);
	set_map_enemy(map);
	return (1);
}

int	check_map_valid(t_map *map, t_list *lines, const char *dir, int fd)
{
	if (!initialize_map(map, dir))
	{
		free_all(*map, lines);
		close(fd);
		return (0);
	}
	return (1);
}
