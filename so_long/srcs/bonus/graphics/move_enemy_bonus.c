/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:25:47 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 19:29:48 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	condition_ene(t_game *game, int *coord_check, int *dir_case, t_dir dir)
{
	int		enemy_y_before;
	int		enemy_x_before;

	enemy_y_before = game->map->enemy->y;
	enemy_x_before = game->map->enemy->x;
	if (dir == MOVE_LEFT)
	{
		*coord_check = game->map->plan[enemy_y_before][enemy_x_before - 1];
		*dir_case = enemy_x_before - 1 < 0;
	}
	else if (dir == MOVE_UP)
	{
		*coord_check = game->map->plan[enemy_y_before - 1][enemy_x_before];
		*dir_case = enemy_y_before - 1 < 0;
	}
	else if (dir == MOVE_RIGHT)
	{
		*coord_check = game->map->plan[enemy_y_before][enemy_x_before + 1];
		*dir_case = enemy_x_before + 1 > game->map->columns - 1;
	}
	else if (dir == MOVE_DOWN)
	{
		*coord_check = game->map->plan[enemy_y_before + 1][enemy_x_before];
		*dir_case = enemy_y_before + 1 > game->map->rows - 1;
	}
}

void	update_enemy_coord(t_game *game, t_dir move_dir)
{
	if (move_dir == MOVE_LEFT)
	{
		game->map->enemy->x--;
		mlx_delete_texture(game->textures.enemy);
		game->textures.enemy = mlx_load_png("images/enemy_left_2.png");
	}
	else if (move_dir == MOVE_UP)
	{
		game->map->enemy->y--;
		mlx_delete_texture(game->textures.enemy);
		game->textures.enemy = mlx_load_png("images/enemy_up.png");
	}
	else if (move_dir == MOVE_RIGHT)
	{
		game->map->enemy->x++;
		mlx_delete_texture(game->textures.enemy);
		game->textures.enemy = mlx_load_png("images/enemy_right.png");
	}
	else if (move_dir == MOVE_DOWN)
	{
		game->map->enemy->y++;
		mlx_delete_texture(game->textures.enemy);
		game->textures.enemy = mlx_load_png("images/enemy_down_2.png");
	}
}

t_component	put_enemy_to_coord(t_game *game, t_component *co_before, t_dir dir)
{
	int			e_x_before;
	int			e_y_before;
	t_coord		en_in_win;
	mlx_image_t	*en_img;

	e_x_before = game->map->enemy->x;
	e_y_before = game->map->enemy->y;
	if (*co_before == ENEMY)
		game->map->plan[e_y_before][e_x_before] = EMPTY_SPACE;
	else
		game->map->plan[e_y_before][e_x_before] = *co_before;
	update_enemy_coord(game, dir);
	*co_before = game->map->plan[game->map->enemy->y][game->map->enemy->x];
	game->map->plan[game->map->enemy->y][game->map->enemy->x] = ENEMY;
	mlx_delete_image(game->window, game->imgs.enemy);
	game->imgs.enemy = mlx_texture_to_image(game->window, game->textures.enemy);
	en_img = game->imgs.enemy;
	en_in_win = get_en_position_with_off_set(game, 6);
	mlx_image_to_window(game->window, en_img, en_in_win.x, en_in_win.y);
	if (*co_before == PLAYER)
	{
		handle_lost(game);
		write_all_messages(game);
	}
	return (*co_before);
}

void	move_enemy(t_game *game, t_dir move_dir)
{
	int					ene_y_before_move;
	int					ene_x_before_move;
	int					dir_case;
	int					coord_to_be_checked;
	static t_component	coord_before_move = 'V';

	ene_y_before_move = game->map->enemy->y;
	ene_x_before_move = game->map->enemy->x;
	dir_case = 1;
	coord_to_be_checked = 1;
	condition_ene(game, &coord_to_be_checked, &dir_case, move_dir);
	if (dir_case || coord_to_be_checked == WALL)
		return ;
	put_enemy_to_coord(game, &coord_before_move, move_dir);
}

void	handle_enemy_move_new(void *param)
{
	t_game		*game;
	static int	i = 1;
	int			rand_num;

	game = (t_game *)param;
	if (game->win || game->lost)
		return ;
	rand_num = -1;
	if (i % DIFFICULTY == 0)
	{
		rand_num = rand() % 4;
		if (rand_num == 0)
			move_enemy(game, MOVE_LEFT);
		else if (rand_num == 1)
			move_enemy(game, MOVE_UP);
		else if (rand_num == 2)
			move_enemy(game, MOVE_RIGHT);
		else if (rand_num == 3)
			move_enemy(game, MOVE_DOWN);
	}
	i++;
	if (i == INT32_MAX)
		i = 1;
}
