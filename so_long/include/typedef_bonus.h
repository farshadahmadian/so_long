/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:33:55 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 17:24:12 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_BONUS_H
# define TYPEDEF_BONUS_H

# include "so_long_bonus.h"

typedef struct s_texture
{
	mlx_texture_t	*pl;
	mlx_texture_t	*coll;
	mlx_texture_t	*exit;
	mlx_texture_t	*wall;
	mlx_texture_t	*empty;
	mlx_texture_t	*enemy;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*pl;
	mlx_image_t	*coll;
	mlx_image_t	*exit;
	mlx_image_t	*wall;
	mlx_image_t	*empty;
	mlx_image_t	*enemy;
}	t_image;

typedef enum s_component
{
	NO_COMPONENT = 0,
	EMPTY_SPACE = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P',
	ENEMY = 'V',
}	t_component;

typedef struct s_surround
{
	t_component	left;
	t_component	up;
	t_component	right;
	t_component	down;
}	t_surround;

typedef struct s_details
{
	int					x;
	int					y;
	int					length;
	t_component			component;
	t_surround			surround;
	struct s_details	*next;
}	t_details;

typedef struct s_valid_path
{
	int		collectible_left;
	int		is_exit_reached;
	char	**map_dup;
}	t_valid_path;

typedef struct s_map
{
	int				rows;
	int				columns;
	t_details		*player;
	t_details		*exit;
	t_details		*collectible;
	t_details		*enemy;
	char			**plan;
	t_valid_path	*valid_path;
}	t_map;

typedef enum s_dir
{
	MOVE_LEFT = 0,
	MOVE_UP,
	MOVE_RIGHT,
	MOVE_DOWN
}	t_dir;

typedef struct s_game
{
	mlx_t		*window;
	t_map		*map;
	t_image		imgs;
	t_texture	textures;
	int			player_move_num;
	int			win;
	int			lost;
	int			is_exit_open;
	mlx_image_t	*string_img_move;
	mlx_image_t	*string_img_coll;
	mlx_image_t	*string_img_end;
}	t_game;

typedef struct s_dimension
{
	int	width;
	int	height;
}	t_dimension;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef mlx_instance_t	t_mlx_inst;

# ifndef DIFFICULTY
#  define DIFFICULTY 20
# endif

#endif
