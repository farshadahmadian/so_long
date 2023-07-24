/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:12:13 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:26:16 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_enemy_details(t_map *map, int x, int y, t_component component)
{
	t_details	*new;
	t_details	*head;

	if (!(map->enemy))
		head = NULL;
	else
		head = map->enemy;
	new = create_new_node(component, x, y);
	details_add_back(&head, new);
	set_surround(map, new, x, y);
	head->length = get_list_length(head);
	map->enemy = head;
}

int	set_map_enemy(t_map *map)
{
	int			y;
	int			x;

	if (!count_component(map, ENEMY))
		return (0);
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if ((map->plan)[y][x] == ENEMY)
				set_enemy_details(map, x, y, ENEMY);
			x++;
		}
		y++;
	}
	return (1);
}
