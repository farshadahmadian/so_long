/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:00:11 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 18:30:10 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->window);
}

t_dimension	calc_window_size(t_map map, mlx_texture_t *texture_data)
{
	t_dimension	dimension;

	ft_bzero(&dimension, sizeof(t_dimension));
	dimension.height = map.rows * texture_data->height;
	dimension.width = map.columns * texture_data->width;
	return (dimension);
}

void	put_all_images_to_window(t_game *game, int x, int y)
{
	if (game->map->plan[y][x] == EMPTY_SPACE)
		put_empty_space_in_window(game, x, y);
	else if (game->map->plan[y][x] == PLAYER)
		put_player_in_window(game, x, y);
	else if (game->map->plan[y][x] == COLLECTIBLE)
		put_collectible_in_window(game, x, y);
	else if (game->map->plan[y][x] == WALL)
		put_wall_in_window(game, x, y);
	else if (game->map->plan[y][x] == EXIT)
		put_exit_in_window(game, x, y);
}

void	ascii_map_to_graphic_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->columns)
		{
			put_all_images_to_window(game, x, y);
			x++;
		}	
		y++;
	}
}

void	create_a_window(t_map *map)
{
	mlx_t		*window;
	t_dimension	dimension;
	t_texture	textures;
	t_image		images;
	t_game		game;

	ft_bzero(&game, sizeof(t_game));
	game.textures.empty = mlx_load_png("images/empty_space.png");
	dimension = calc_window_size(*map, game.textures.empty);
	window = mlx_init(dimension.width, dimension.height, "so_long", 0);
	game.map = map;
	game.window = window;
	mlx_delete_texture(game.textures.empty);
	ft_bzero(&(game.textures), sizeof(t_texture));
	textures = create_all_textures();
	game.textures = textures;
	images = create_all_images(&game);
	game.imgs = images;
	ascii_map_to_graphic_map(&game);
	mlx_key_hook(window, handle_move, &game);
	mlx_loop(window);
	delete_all_textures(&game);
	delete_all_images(&game);
	mlx_terminate(window);
}
