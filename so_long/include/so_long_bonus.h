/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:36:18 by fahmadia          #+#    #+#             */
/*   Updated: 2023/07/20 19:14:27 by fahmadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include "MLX42.h"
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "typedef_bonus.h"

int			check_file_extension(const char *file_dir, const char *extension);
t_list		*read_map(int map_fd);
int			create_copy(t_map *map, t_list *lines, int map_fd);
void		free_double_pointer(char **ptr, int i);
void		free_list(t_list *head, void (*free_content)(t_list *current_node));
int			check_map_rectangle(t_map *map);
int			check_components(t_map *map);
void		get_map_size(t_map *map);
int			set_map_player(t_map *map);
int			check_map_valid(t_map *map, t_list *lines, const char *dir, int fd);
int			set_map_collectible(t_map *map);
t_details	*create_new_node(t_component component, int x, int y);
void		details_add_back(t_details **details, t_details *new);
int			get_list_length(t_details *details);
void		set_surround(t_map *map, t_details	*new, int x, int y);
int			count_component(t_map *map, t_component component);
int			set_map_exit(t_map *map);
int			check_map_is_closed(t_map *map);
void		free_line(t_list *head);
void		free_t_details(t_details *head);
void		free_all(t_map map, t_list *lines);
int			check_valid_path(t_map *map);
void		create_a_window(t_map *map);
t_image		create_all_images(t_game *game);
void		print_duplicate(char **duplicate);
void		handle_move(mlx_key_data_t key_data, void *param);
void		ascii_map_to_graphic_map(t_game *game);
void		delete_all_images(t_game *game);
void		update_graphical_map(t_game *game);
t_texture	create_all_textures(void);
void		delete_all_textures(t_game *game);
void		put_empty_space_in_window(t_game *game, int x, int y);
void		put_player_in_window(t_game *game, int x, int y);
void		put_collectible_in_window(t_game *game, int x, int y);
void		put_wall_in_window(t_game *game, int x, int y);
void		put_exit_in_window(t_game *game, int x, int y);
void		handle_player_go_to_exit(t_game *game, int *move_num, t_dir dir);
void		handle_player_out_of_exit(t_game *game, int *move_num, t_dir dir);
void		handle_game_end(t_game *game, int *move_num, int *win, t_dir dir);
void		update_palyer_coord(t_game *game, t_dir move_dir);
void		handle_player_to_em_or_coll(t_game *game, int *move_num, t_dir dir);
void		write_all_messages(t_game *game);
int			set_map_enemy(t_map *map);
void		put_enemy_in_window(t_game *game, int x, int y);
void		handle_enemy_move_new(void *param);
t_coord		get_pl_position_with_off_set(t_game *game, int off_set);
t_coord		get_en_position_with_off_set(t_game *game, int off_set);
t_coord		get_exit_position(t_game *game);
t_mlx_inst	*get_a_coll_instance(t_game *game, int x, int y);
t_component	put_pl_to_coord(t_game *game, t_component *com_before, t_dir dir);
void		delete_textures_and_images(t_game *game);
void		handle_lost(t_game *game);

#endif
