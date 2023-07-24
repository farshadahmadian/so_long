/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:11:38 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 18:29:40 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_texture	create_all_textures(void)
{
	t_texture	textures;

	ft_bzero(&textures, sizeof(t_texture));
	textures.pl = mlx_load_png("images/player3_down.png");
	textures.coll = mlx_load_png("images/collectible.png");
	textures.exit = mlx_load_png("images/exit_closed.png");
	textures.wall = mlx_load_png("images/wall.png");
	textures.empty = mlx_load_png("images/empty_space.png");
	return (textures);
}

void	delete_all_textures(t_game *game)
{
	mlx_delete_texture(game->textures.coll);
	mlx_delete_texture(game->textures.empty);
	mlx_delete_texture(game->textures.exit);
	mlx_delete_texture(game->textures.pl);
	mlx_delete_texture(game->textures.wall);
}

t_image	create_all_images(t_game *game)
{
	t_image		images;

	ft_bzero(&images, sizeof(t_image));
	images.pl = mlx_texture_to_image(game->window, game->textures.pl);
	images.coll = mlx_texture_to_image(game->window, game->textures.coll);
	images.exit = mlx_texture_to_image(game->window, game->textures.exit);
	images.wall = mlx_texture_to_image(game->window, game->textures.wall);
	images.empty = mlx_texture_to_image(game->window, game->textures.empty);
	return (images);
}

void	delete_all_images(t_game *game)
{
	mlx_delete_image(game->window, game->imgs.coll);
	mlx_delete_image(game->window, game->imgs.pl);
	mlx_delete_image(game->window, game->imgs.wall);
	mlx_delete_image(game->window, game->imgs.exit);
	mlx_delete_image(game->window, game->imgs.empty);
}

void	update_graphical_map(t_game *game)
{
	delete_all_images(game);
	game->imgs = create_all_images(game);
	ascii_map_to_graphic_map(game);
}
