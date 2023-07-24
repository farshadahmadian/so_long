/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_coll_instance_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:54:18 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:25:01 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_instance_t	*get_a_coll_instance(t_game *game, int x, int y)
{
	int				i;
	mlx_instance_t	*target_instance;
	mlx_image_t		*em;
	mlx_image_t		*coll;
	mlx_instance_t	*cur_inst;

	if (game->map->plan[y][x] != COLLECTIBLE)
		return (NULL);
	i = 0;
	target_instance = NULL;
	em = game->imgs.empty;
	coll = game->imgs.coll;
	cur_inst = coll->instances;
	while (i < (int)(coll->count))
	{
		if ((cur_inst[i]).x == (int)(x * em->width + (coll->width) / 2)
			&& (cur_inst[i]).y == (int)(y * em->height + (coll->height) / 2))
			target_instance = &(cur_inst[i]);
		i++;
	}
	return (target_instance);
}
