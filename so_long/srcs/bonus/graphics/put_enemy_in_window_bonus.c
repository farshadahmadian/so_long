/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_enemy_in_window_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:22:58 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:25:33 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_enemy_in_window(t_game *game, int x, int y)
{
	mlx_image_t	*em;
	mlx_image_t	*enemy;
	mlx_image_t	*exit;
	int			enemy_x;
	int			enemy_y;

	em = game->imgs.empty;
	enemy = game->imgs.enemy;
	exit = game->imgs.exit;
	enemy_x = x * em->width + (enemy->width) / 6;
	enemy_y = y * em->height + (enemy->height) / 6;
	put_empty_space_in_window(game, x, y);
	mlx_image_to_window(game->window, enemy, enemy_x, enemy_y);
}
