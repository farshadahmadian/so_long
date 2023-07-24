/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:53:30 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 18:44:18 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_palyer_coord(t_game *game, t_dir move_dir)
{
	if (move_dir == MOVE_LEFT)
		game->map->player->x--;
	else if (move_dir == MOVE_UP)
		game->map->player->y--;
	else if (move_dir == MOVE_RIGHT)
		game->map->player->x++;
	else if (move_dir == MOVE_DOWN)
		game->map->player->y++;
}

void	condition(t_game *game, int *coord_check, int *dir_case, t_dir dir)
{
	int		p_y_before;
	int		p_x_before;

	p_y_before = game->map->player->y;
	p_x_before = game->map->player->x;
	if (dir == MOVE_LEFT)
	{
		*coord_check = game->map->plan[p_y_before][p_x_before - 1];
		*dir_case = p_x_before - 1 < 0;
	}
	else if (dir == MOVE_UP)
	{
		*coord_check = game->map->plan[p_y_before - 1][p_x_before];
		*dir_case = p_y_before - 1 < 0;
	}
	else if (dir == MOVE_RIGHT)
	{
		*coord_check = game->map->plan[p_y_before][p_x_before + 1];
		*dir_case = p_x_before + 1 > game->map->columns - 1;
	}
	else if (dir == MOVE_DOWN)
	{
		*coord_check = game->map->plan[p_y_before + 1][p_x_before];
		*dir_case = p_y_before + 1 > game->map->rows - 1;
	}
}

void	move_player(t_game *game, int *move_num, int *win, t_dir move_dir)
{
	int		player_y_before_move;
	int		player_x_before_move;
	int		dir_case;
	int		coord_to_be_checked;

	player_y_before_move = game->map->player->y;
	player_x_before_move = game->map->player->x;
	dir_case = 1;
	coord_to_be_checked = 1;
	condition(game, &coord_to_be_checked, &dir_case, move_dir);
	if (dir_case || coord_to_be_checked == WALL)
		return ;
	if (!game->map->collectible->length && coord_to_be_checked == EXIT)
		return (handle_game_end(game, move_num, win, move_dir));
	if (game->map->collectible->length && coord_to_be_checked == EXIT)
	{
		handle_player_go_to_exit(game, move_num, move_dir);
		return ;
	}
	if (coord_to_be_checked == COLLECTIBLE)
		game->map->collectible->length--;
	if (game->map->exit->x == -1 && game->map->exit->y == -1)
		handle_player_out_of_exit(game, move_num, move_dir);
	else
		handle_player_to_em_or_coll(game, move_num, move_dir);
}

void	handle_player_out(t_game *game)
{
	put_empty_space_in_window(game, game->map->player->x, game->map->player->y);
	put_exit_in_window(game, game->map->player->x, game->map->player->y);
}

void	handle_move(mlx_key_data_t key_data, void *param)
{
	t_game		*game;
	static int	move_num;
	static int	win;
	int			key_event;

	key_event = (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT);
	game = (t_game *)param;
	if (key_data.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->window);
	if (win)
		return (handle_player_out(game));
	if (key_data.key == MLX_KEY_A && key_event)
		move_player(game, &move_num, &win, MOVE_LEFT);
	else if (key_data.key == MLX_KEY_W && key_event)
		move_player(game, &move_num, &win, MOVE_UP);
	else if (key_data.key == MLX_KEY_D && key_event)
		move_player(game, &move_num, &win, MOVE_RIGHT);
	else if (key_data.key == MLX_KEY_S && key_event)
		move_player(game, &move_num, &win, MOVE_DOWN);
	if (!game->map->collectible->length)
	{
		mlx_delete_texture(game->textures.exit);
		game->textures.exit = mlx_load_png("images/exit_open.png");
	}
	update_graphical_map(game);
}
