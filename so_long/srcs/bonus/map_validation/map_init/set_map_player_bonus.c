/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:28:53 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:26:25 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_surround(t_map *map, t_details	*new, int x, int y)
{
	if (x - 1 >= 0)
		new->surround.left = map->plan[y][x - 1];
	else
		new->surround.left = -1;
	if (y - 1 >= 0)
		new->surround.up = map->plan[y - 1][x];
	else
		new->surround.up = -1;
	if (x + 1 < map->columns)
		new->surround.right = map->plan[y][x + 1];
	else
		new->surround.right = -1;
	if (y + 1 < map->rows)
		new->surround.down = map->plan[y + 1][x];
	else
		new->surround.down = -1;
}

void	set_player_details(t_map *map, int x, int y, t_component component)
{
	t_details	*new;
	t_details	*head;

	if (!(map->player))
		head = NULL;
	else
		head = map->player;
	new = create_new_node(component, x, y);
	details_add_back(&head, new);
	set_surround(map, new, x, y);
	head->length = get_list_length(head);
	map->player = head;
}

void	print_more_than_one_player(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Only one player is allowed!", 2);
}

void	print_no_player(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("No player is found!", 2);
}

int	set_map_player(t_map *map)
{
	int			y;
	int			x;

	if (!count_component(map, PLAYER))
	{
		return (print_no_player(), 0);
	}
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if ((map->plan)[y][x] == PLAYER)
				set_player_details(map, x, y, PLAYER);
			x++;
		}
		y++;
	}
	if (map->player->length != 1)
	{
		print_more_than_one_player();
		return (0);
	}
	return (1);
}
