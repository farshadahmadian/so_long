/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_on_map_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:57:14 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 19:28:21 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_palyer_coord(t_game *game, t_dir move_dir)
{
	if (move_dir == MOVE_LEFT)
	{
		game->map->player->x--;
		mlx_delete_texture(game->textures.pl);
		game->textures.pl = mlx_load_png("images/player_left.png");
	}
	else if (move_dir == MOVE_UP)
	{
		game->map->player->y--;
		mlx_delete_texture(game->textures.pl);
		game->textures.pl = mlx_load_png("images/player_up.png");
	}
	else if (move_dir == MOVE_RIGHT)
	{
		game->map->player->x++;
		mlx_delete_texture(game->textures.pl);
		game->textures.pl = mlx_load_png("images/player_right.png");
	}
	else if (move_dir == MOVE_DOWN)
	{
		game->map->player->y++;
		mlx_delete_texture(game->textures.pl);
		game->textures.pl = mlx_load_png("images/player_down.png");
	}
}

void	put_player_to_coll(t_game *game, t_details *player)
{	
	mlx_instance_t	*target_instance;

	target_instance = NULL;
	target_instance = get_a_coll_instance(game, player->x, player->y);
	if (!target_instance)
		return ;
	target_instance->enabled = false;
	game->map->collectible->length--;
}

void	player_out(t_game *game)
{
	game->win = 1;
	put_empty_space_in_window(game, game->map->player->x, game->map->player->y);
	put_exit_in_window(game, game->map->player->x, game->map->player->y);
}

void	handle_lost(t_game *game)
{
	t_coord	pl_coord;
	t_coord	en_coord;

	game->lost = 1;
	pl_coord = get_pl_position_with_off_set(game, 3);
	mlx_delete_texture(game->textures.pl);
	mlx_delete_image(game->window, game->imgs.pl);
	game->textures.pl = mlx_load_png("images/player_dead.png");
	game->imgs.pl = mlx_texture_to_image(game->window, game->textures.pl);
	mlx_image_to_window(game->window, game->imgs.pl, pl_coord.x, pl_coord.y);
	en_coord = get_en_position_with_off_set(game, 10);
	mlx_delete_texture(game->textures.enemy);
	mlx_delete_image(game->window, game->imgs.enemy);
	game->textures.enemy = mlx_load_png("images/enemy_won.png");
	game->imgs.enemy = mlx_texture_to_image(game->window, game->textures.enemy);
	mlx_image_to_window(game->window, game->imgs.enemy, en_coord.x, en_coord.y);
}

t_component	put_pl_to_coord(t_game *game, t_component *com_before, t_dir dir)
{
	t_coord			pl_in_win;
	t_details		*player;

	player = game->map->player;
	if (*com_before == EXIT)
		game->map->plan[player->y][player->x] = EXIT;
	else
		game->map->plan[player->y][player->x] = EMPTY_SPACE;
	update_palyer_coord(game, dir);
	*com_before = game->map->plan[player->y][player->x];
	if (*com_before == COLLECTIBLE)
		put_player_to_coll(game, player);
	game->map->plan[player->y][player->x] = PLAYER;
	mlx_delete_image(game->window, game->imgs.pl);
	game->imgs.pl = mlx_texture_to_image(game->window, game->textures.pl);
	pl_in_win = get_pl_position_with_off_set(game, 3);
	mlx_image_to_window(game->window, game->imgs.pl, pl_in_win.x, pl_in_win.y);
	if (*com_before == ENEMY)
		handle_lost(game);
	else if (*com_before == EXIT && game->is_exit_open)
		return (player_out(game), *com_before);
	return (*com_before);
}
