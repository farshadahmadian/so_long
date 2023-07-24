/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_components_in_window_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 08:19:12 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 19:21:11 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_empty_space_in_window(t_game *game, int x, int y)
{
	mlx_image_t	*emp;

	emp = game->imgs.empty;
	mlx_image_to_window(game->window, emp, x * emp->width, y * emp->height);
}

void	put_player_in_window(t_game *game, int x, int y)
{
	mlx_image_t	*em;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	int			p_x;
	int			p_y;

	em = game->imgs.empty;
	player = game->imgs.pl;
	exit = game->imgs.exit;
	p_x = x * em->width + (player->width) / 3;
	p_y = y * em->height + (player->height) / 3;
	if (game->map->exit->x == -1 && game->map->exit->y == -1)
	{
		put_empty_space_in_window(game, x, y);
		put_exit_in_window(game, x, y);
		mlx_image_to_window(game->window, player, p_x, p_y);
	}
	else
	{
		put_empty_space_in_window(game, x, y);
		mlx_image_to_window(game->window, player, p_x, p_y);
	}
}

void	put_collectible_in_window(t_game *game, int x, int y)
{
	mlx_image_t	*em;
	mlx_image_t	*collectible;
	int			coll_x;
	int			coll_y;

	em = game->imgs.empty;
	collectible = game->imgs.coll;
	coll_x = x * em->width + (collectible->width) / 2;
	coll_y = y * em->height + (collectible->height) / 2;
	put_empty_space_in_window(game, x, y);
	mlx_image_to_window(game->window, collectible, coll_x, coll_y);
}

void	put_wall_in_window(t_game *game, int x, int y)
{
	mlx_image_t	*em;
	mlx_image_t	*wall;

	em = game->imgs.empty;
	wall = game->imgs.wall;
	mlx_image_to_window(game->window, wall, x * em->width, y * em->height);
}

void	put_exit_in_window(t_game *game, int x, int y)
{
	mlx_image_t	*em;
	mlx_image_t	*exit;

	em = game->imgs.empty;
	exit = game->imgs.exit;
	put_empty_space_in_window(game, x, y);
	mlx_image_to_window(game->window, exit, x * em->width, y * em->height);
}
