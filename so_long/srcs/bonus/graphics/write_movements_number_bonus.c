/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_movements_number_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:55:00 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:25:43 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	calc_center_x(t_game *game, char *message, int font_size)
{
	int		length;
	int		window_width;
	int		center_x;

	length = (int)(ft_strlen(message) * font_size);
	window_width = game->window->width;
	center_x = (window_width / 2) - (length / 2);
	return (center_x);
}

mlx_image_t	*write_message_in_window(t_game *game, char *msg, int num, int y)
{
	char		*num_text;
	int			center_x;
	int			font_size;
	mlx_image_t	*string_image;

	string_image = NULL;
	font_size = 10;
	center_x = calc_center_x(game, msg, font_size);
	if (!msg)
		return (string_image);
	if (num == -1)
	{
		string_image = mlx_put_string(game->window, msg, center_x, y);
		return (string_image);
	}
	num_text = ft_itoa(num);
	msg = ft_strjoin(msg, num_text);
	string_image = mlx_put_string(game->window, msg, center_x, y);
	free(num_text);
	free(msg);
	return (string_image);
}

void	write_move_num(t_game *game)
{
	char				*message;
	int					move_num;
	int					y;
	static mlx_image_t	*move_string_image;

	if (move_string_image)
		mlx_delete_image(game->window, move_string_image);
	if (!game)
		return ;
	move_num = game->player_move_num;
	y = game->window->height - 40;
	message = "Movements: ";
	move_string_image = write_message_in_window(game, message, move_num, y);
	game->string_img_move = move_string_image;
}

void	write_collectible_num(t_game *game)
{
	char				*message;
	int					colle_length;
	int					y;
	static mlx_image_t	*coll_string_image;

	if (coll_string_image)
		mlx_delete_image(game->window, coll_string_image);
	if (!game)
		return ;
	colle_length = game->map->collectible->length;
	y = game->window->height - 20;
	message = "Collectibles: ";
	coll_string_image = write_message_in_window(game, message, colle_length, y);
	game->string_img_coll = coll_string_image;
}

void	write_all_messages(t_game *game)
{
	char	*end_msg;
	int		window_width;

	window_width = game->window->width;
	write_move_num(game);
	write_collectible_num(game);
	if (game->win)
	{	
		end_msg = "YOU WON!";
		game->string_img_end = write_message_in_window(game, end_msg, -1, 20);
	}
	else if (game->lost)
	{
		end_msg = "GAME OVER!";
		game->string_img_end = write_message_in_window(game, end_msg, -1, 20);
	}
}
