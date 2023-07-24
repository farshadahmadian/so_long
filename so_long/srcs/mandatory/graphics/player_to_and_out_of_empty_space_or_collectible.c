/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_to_and_out_of_empty_space_or_collect        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:49:31 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 10:08:49 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	switch_player_and_em_space(t_game *game, int p_x_before, int p_y_before)
{
	game->map->plan[p_y_before][p_x_before] = EMPTY_SPACE;
	game->map->plan[game->map->player->y][game->map->player->x] = PLAYER;
}

void	handle_player_to_em_or_coll(t_game *game, int *move_num, t_dir dir)
{
	int		p_y_before;
	int		p_x_before;

	p_y_before = game->map->player->y;
	p_x_before = game->map->player->x;
	update_palyer_coord(game, dir);
	switch_player_and_em_space(game, p_x_before, p_y_before);
	(*move_num)++;
	ft_printf("Number of movements: %d\n", (*move_num));
}
