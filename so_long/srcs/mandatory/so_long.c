/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:36:13 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 18:01:32 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*map_dir;
	int		map_fd;
	t_list	*lines;
	t_map	map;

	if (argc < 2)
		return (1);
	map_dir = argv[1];
	ft_bzero(&map, sizeof(t_map));
	map_fd = open(map_dir, O_RDONLY);
	if (map_fd < 0)
		return (1);
	lines = read_map(map_fd);
	if (!lines)
		return (1);
	if (!create_copy(&map, lines, map_fd))
		return (1);
	if (!check_map_valid(&map, lines, map_dir, map_fd))
		return (1);
	create_a_window(&map);
	free_all(map, lines);
	close(map_fd);
	return (0);
}
