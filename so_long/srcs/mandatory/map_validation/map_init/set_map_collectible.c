/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_collectible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:45:52 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 09:39:46 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_collectible_details(t_map *map, int x, int y, t_component component)
{
	t_details	*new;
	t_details	*head;

	if (!(map->collectible))
		head = NULL;
	else
		head = map->collectible;
	new = create_new_node(component, x, y);
	details_add_back(&head, new);
	set_surround(map, new, x, y);
	head->length = get_list_length(head);
	map->collectible = head;
}

int	set_map_collectible(t_map *map)
{
	int			y;
	int			x;

	if (!count_component(map, COLLECTIBLE))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("No collectible found!", 2);
		return (0);
	}
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if ((map->plan)[y][x] == COLLECTIBLE)
				set_collectible_details(map, x, y, COLLECTIBLE);
			x++;
		}
		y++;
	}
	return (1);
}
