/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:53:30 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:25:11 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	move_player(t_game *game, t_dir move_dir)
{
	int					dir_case;
	int					coord_to_be_checked;
	static t_component	coord_before_move = PLAYER;

	dir_case = 1;
	coord_to_be_checked = 1;
	condition(game, &coord_to_be_checked, &dir_case, move_dir);
	if (dir_case || coord_to_be_checked == WALL || game->win)
		return ;
	game->player_move_num++;
	put_pl_to_coord(game, &coord_before_move, move_dir);
}

void	open_exit(t_game *game, int	*is_exit_open)
{
	t_coord	exit_win;

	mlx_delete_image(game->window, game->imgs.exit);
	mlx_delete_texture(game->textures.exit);
	game->textures.exit = mlx_load_png("images/exit_open.png");
	game->imgs.exit = mlx_texture_to_image(game->window, game->textures.exit);
	exit_win = get_exit_position(game);
	mlx_image_to_window(game->window, game->imgs.exit, exit_win.x, exit_win.y);
	*is_exit_open = 1;
	game->is_exit_open = 1;
}

void	handle_move(mlx_key_data_t key_data, void *param)
{
	t_game		*game;
	int			key_event;
	static int	is_exit_open;

	key_event = (key_data.action == MLX_PRESS || key_data.action == MLX_REPEAT);
	game = (t_game *)param;
	if (key_data.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->window);
	if (game->win || game->lost)
		return ;
	if (key_data.key == MLX_KEY_A && key_event)
		move_player(game, MOVE_LEFT);
	else if (key_data.key == MLX_KEY_W && key_event)
		move_player(game, MOVE_UP);
	else if (key_data.key == MLX_KEY_D && key_event)
		move_player(game, MOVE_RIGHT);
	else if (key_data.key == MLX_KEY_S && key_event)
		move_player(game, MOVE_DOWN);
	if (!game->map->collectible->length && !is_exit_open)
		open_exit(game, &is_exit_open);
	write_all_messages(game);
}
