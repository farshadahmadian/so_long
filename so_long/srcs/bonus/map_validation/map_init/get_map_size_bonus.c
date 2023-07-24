/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:08:28 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:26:04 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_map_size(t_map *map)
{
	char	**temp;
	int		i;

	i = 0;
	temp = map->plan;
	while (*temp)
	{
		i++;
		temp++;
	}
	map->rows = i;
	i = 0;
	while (i < map->rows)
		i++;
	map->columns = (int)ft_strlen((map->plan)[0]);
}
