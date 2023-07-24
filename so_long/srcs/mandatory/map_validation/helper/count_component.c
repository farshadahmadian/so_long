/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_component.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:18:43 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/14 18:14:19 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_component(t_map *map, t_component component)
{
	int	i;
	int	j;
	int	component_count;

	i = 0;
	component_count = 0;
	while ((map->plan)[i])
	{
		j = 0;
		while ((map->plan)[i][j])
		{
			if ((map->plan)[i][j] == (char)component)
				component_count++;
			j++;
		}
		i++;
	}
	return (component_count);
}
