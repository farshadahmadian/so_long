/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:35:24 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/19 20:52:54 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_map map, t_list *lines)
{
	free_list(lines, free_line);
	free_double_pointer(map.plan, map.rows - 1);
	if (map.player)
		free_t_details(map.player);
	if (map.collectible)
		free_t_details(map.collectible);
	if (map.exit)
		free_t_details(map.exit);
	if (map.valid_path)
	{
		free_double_pointer(map.valid_path->map_dup, map.rows - 1);
		free(map.valid_path);
	}
}
