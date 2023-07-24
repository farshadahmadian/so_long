/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_component_position_in_window_bonus.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:49:33 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:25:04 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_coord	get_pl_position_with_off_set(t_game *game, int off_set)
{
	mlx_image_t	*em_img;
	mlx_image_t	*pl_img;
	t_details	*player;
	t_coord		coord_on_window;

	pl_img = game->imgs.pl;
	player = game->map->player;
	em_img = game->imgs.empty;
	coord_on_window.x = player->x * em_img->width + (pl_img->width) / off_set;
	coord_on_window.y = player->y * em_img->height + (pl_img->height) / off_set;
	return (coord_on_window);
}

t_coord	get_en_position_with_off_set(t_game *game, int off_set)
{
	mlx_image_t	*em_img;
	mlx_image_t	*en_img;
	t_details	*enemy;
	t_coord		coord_on_window;

	en_img = game->imgs.enemy;
	enemy = game->map->enemy;
	em_img = game->imgs.empty;
	coord_on_window.x = enemy->x * em_img->width + (en_img->width) / off_set;
	coord_on_window.y = enemy->y * em_img->height + (en_img->height) / off_set;
	return (coord_on_window);
}

t_coord	get_exit_position(t_game *game)
{
	mlx_image_t	*em_img;
	t_details	*exit;
	t_coord		coord_on_window;

	exit = game->map->exit;
	em_img = game->imgs.empty;
	coord_on_window.x = exit->x * em_img->width;
	coord_on_window.y = exit->y * em_img->height;
	return (coord_on_window);
}
