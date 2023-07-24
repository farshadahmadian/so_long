/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_textures_and_images_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:29:23 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:24:54 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	delete_textures_and_images(t_game *game)
{
	delete_all_textures(game);
	delete_all_images(game);
	if (game->string_img_coll)
		mlx_delete_image(game->window, game->string_img_coll);
	if (game->string_img_move)
		mlx_delete_image(game->window, game->string_img_move);
	if (game->string_img_end)
		mlx_delete_image(game->window, game->string_img_end);
}
