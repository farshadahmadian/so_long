/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_to_and_out_of_exit_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:41:11 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:25:26 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player_to_exit(t_game *game, int p_x_before, int p_y_before)
{
	game->map->plan[p_y_before][p_x_before] = EMPTY_SPACE;
	game->map->plan[game->map->player->y][game->map->player->x] = PLAYER;
	game->map->exit->x = -1;
	game->map->exit->y = -1;
}

void	handle_player_go_to_exit(t_game *game, int *move_num, t_dir dir)
{
	int		player_y_before_move;
	int		player_x_before_move;

	player_y_before_move = game->map->player->y;
	player_x_before_move = game->map->player->x;
	update_palyer_coord(game, dir);
	put_player_to_exit(game, player_x_before_move, player_y_before_move);
	(*move_num)++;
	ft_printf("Number of movements: %d\n", (*move_num));
}

void	handle_player_out_of_exit(t_game *game, int *move_num, t_dir dir)
{
	int		player_y_before_move;
	int		player_x_before_move;

	player_y_before_move = game->map->player->y;
	player_x_before_move = game->map->player->x;
	game->map->exit->x = player_x_before_move;
	game->map->exit->y = player_y_before_move;
	game->map->plan[player_y_before_move][player_x_before_move] = EXIT;
	update_palyer_coord(game, dir);
	game->map->plan[game->map->player->y][game->map->player->x] = PLAYER;
	(*move_num)++;
	ft_printf("Number of movements: %d\n", (*move_num));
}

void	handle_game_end(t_game *game, int *move_num, int *win, t_dir dir)
{
	int		player_y_before_move;
	int		player_x_before_move;

	player_y_before_move = game->map->player->y;
	player_x_before_move = game->map->player->x;
	*win = 1;
	update_palyer_coord(game, dir);
	put_player_to_exit(game, player_x_before_move, player_y_before_move);
	(*move_num)++;
	ft_printf("Number of movements: %d\n", (*move_num));
}
