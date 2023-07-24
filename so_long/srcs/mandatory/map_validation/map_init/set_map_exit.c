/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:07:39 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:53:14 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_exit_details(t_map *map, int x, int y, t_component component)
{
	t_details	*new;
	t_details	*head;

	if (!(map->exit))
		head = NULL;
	else
		head = map->exit;
	new = create_new_node(component, x, y);
	details_add_back(&head, new);
	set_surround(map, new, x, y);
	head->length = get_list_length(head);
	map->exit = head;
}

void	print_more_than_one_exit(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Only one exit is allowed!", 2);
}

void	print_no_exit(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("No exit is found!", 2);
}

int	set_map_exit(t_map *map)
{
	int			y;
	int			x;

	if (!count_component(map, EXIT))
		return (print_no_exit(), 0);
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if ((map->plan)[y][x] == EXIT)
				set_exit_details(map, x, y, EXIT);
			x++;
		}
		y++;
	}
	if (map->exit->length != 1)
		return (print_more_than_one_exit(), 0);
	return (1);
}
