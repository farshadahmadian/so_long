# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fahmadia <fahmadia@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 08:17:21 by fahmadia          #+#    #+#              #
#    Updated: 2023/08/19 09:21:43 by fahmadia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = ./srcs/mandatory/map_validation\
	./srcs/mandatory/map_validation/memory_management\
	./srcs/mandatory/map_validation/helper\
	./srcs/mandatory/map_validation/map_init\
	./srcs/mandatory/graphics\
	./srcs/mandatory\

SRCS = so_long.c\
	check_file_extension.c\
	read_map.c\
	copy_map.c\
	free_double_pointer.c\
	free_lines.c\
	check_map_rectangle.c\
	check_components.c\
	get_map_size.c\
	set_map_player.c\
	check_map_validation.c\
	set_map_collectible.c\
	handle_lists.c\
	count_component.c\
	set_map_exit.c\
	check_map_is_closed.c\
	free_line.c\
	free_t_details.c\
	free_all.c\
	check_valid_path.c\
	handle_window.c\
	handle_images.c\
	handle_movement.c\
	put_components_in_window.c\
	player_to_and_out_of_exit.c\
	player_to_and_out_of_empty_space_or_collectible.c\

BONUS = ./srcs/bonus/so_long_bonus.c\
	./srcs/bonus/map_validation/check_file_extension_bonus.c\
	./srcs/bonus/map_validation/map_init/read_map_bonus.c\
	./srcs/bonus/map_validation/map_init/copy_map_bonus.c\
	./srcs/bonus/map_validation/memory_management/free_double_pointer_bonus.c\
	./srcs/bonus/map_validation/memory_management/free_lines_bonus.c\
	./srcs/bonus/map_validation/check_map_rectangle_bonus.c\
	./srcs/bonus/map_validation/check_components_bonus.c\
	./srcs/bonus/map_validation/map_init/get_map_size_bonus.c\
	./srcs/bonus/map_validation/map_init/set_map_player_bonus.c\
	./srcs/bonus/map_validation/map_init/check_map_validation_bonus.c\
	./srcs/bonus/map_validation/map_init/set_map_collectible_bonus.c\
	./srcs/bonus/map_validation/helper/handle_lists_bonus.c\
	./srcs/bonus/map_validation/helper/count_component_bonus.c\
	./srcs/bonus/map_validation/map_init/set_map_exit_bonus.c\
	./srcs/bonus/map_validation/check_map_is_closed_bonus.c\
	./srcs/bonus/map_validation/memory_management/free_line_bonus.c\
	./srcs/bonus/map_validation/memory_management/free_t_details_bonus.c\
	./srcs/bonus/map_validation/memory_management/free_all_bonus.c\
	./srcs/bonus/map_validation/check_valid_path_bonus.c\
	./srcs/bonus/graphics/handle_window_bonus.c\
	./srcs/bonus/graphics/handle_images_bonus.c\
	./srcs/bonus/graphics/handle_movement_bonus.c\
	./srcs/bonus/graphics/put_components_in_window_bonus.c\
	./srcs/bonus/graphics/player_to_and_out_of_exit_bonus.c\
	./srcs/bonus/graphics/player_to_and_out_of_empty_space_or_collectible_bonus.c\
	./srcs/bonus/map_validation/map_init/set_map_enemy_bonus.c\
	./srcs/bonus/graphics/put_enemy_in_window_bonus.c\
	./srcs/bonus/graphics/move_enemy_bonus.c\
	./srcs/bonus/graphics/write_movements_number_bonus.c\
	./srcs/bonus/graphics/get_component_position_in_window_bonus.c\
	./srcs/bonus/graphics/get_a_coll_instance_bonus.c\
	./srcs/bonus/graphics/update_player_on_map_bonus.c\
	srcs/bonus/graphics/delete_textures_and_images_bonus.c

INCLUDE_DIR = -I./include\
	-I./libmylib/libft\
	-I./libmylib/ft_printf\
	-I./libmylib/get_next_line\
	-I./mlx42/include/MLX42

# GLFW_PATH = /Users/$(USER)/.brew/opt/glfw/lib
# GLFW_PATH = /Users/$(USER)/.brew/Cellar/glfw/3.3.8/lib
GLFW_PATH = /Users/$(USER)/goinfre/.brew/opt/glfw/lib

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS_DIR = ./objs
OBJS_FLAG = $(OBJS_DIR)/mandatory_flag
BONUS_DIR= ./objs/bonus

ifneq ($(filter bonus,$(MAKECMDGOALS)),)
	OBJS = $(patsubst %.c, $(BONUS_DIR)/%.o, $(BONUS))
	OBJS_FLAG = $(BONUS_DIR)/bonus_flag
endif

DEPENDENCIES = $(OBJS:.o=.d)
DEPENDENCIES_BONUS = $(BONUS_OBJS:.o=.d)

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX42LIB_PATH = ./mlx42/build
MLX42LIB = $(MLX42LIB_PATH)/libmlx42.a
LIBMYLIB_PATH = ./libmylib
LIBMYLIB = $(LIBMYLIB_PATH)/libmylib.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX42LIB) $(LIBMYLIB) $(OBJS_FLAG) Makefile
	$(CC) $(OBJS) -lmlx42 -L$(MLX42LIB_PATH) -lglfw -L$(GLFW_PATH) -lmylib -L$(LIBMYLIB_PATH) -g -o $(NAME)

$(OBJS_DIR)/%.o: %.c $(MLX42LIB) $(LIBMYLIB) Makefile 
	mkdir -p $(OBJS_DIR)
	$(CC) -c -MMD -g $(CFLAGS) $(INCLUDE_DIR) $< -o $@ 

$(LIBMYLIB):
	make -C $(LIBMYLIB_PATH)

$(MLX42LIB):
##############################install brew:
# curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

##############################install cmake:
# brew install cmake

##############################install glfw
# brew install glfw

##############################clone mlx42 library
# git clone https://github.com/codam-coding-college/MLX42.git mlx42

##############################create mlx42.a
# cd ./mlx42 && cmake -B build
# make -C ./mlx42/build -j4

bonus: $(NAME)

$(BONUS_DIR)/%.o: %.c $(MLX42LIB) $(LIBMYLIB) Makefile 
	mkdir -p $(OBJS_DIR)/bonus
	mkdir -p ${@D}
	$(CC) -c -MMD -g $(CFLAGS) $(INCLUDE_DIR) $< -o $@ 

$(OBJS_FLAG):
	rm -f $(OBJS_DIR)/mandatory_flag
	rm -f $(BONUS_DIR)/bonus_flag
	touch $(OBJS_FLAG)

clean: 
	rm -f $(OBJS)
	rm -f $(DEPENDENCIES)
	rm -f $(DEPENDENCIES_BONUS)
	make clean -C $(LIBMYLIB_PATH)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)
	make fclean -C $(LIBMYLIB_PATH)

re:
	make fclean
	make all

.PHONY: all clean fclean re bonus

-include $(DEPENDENCIES)
-include $(DEPENDENCIES_BONUS)
