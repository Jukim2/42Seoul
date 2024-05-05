# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 18:10:56 by jukim2            #+#    #+#              #
#    Updated: 2023/11/19 21:55:25 by jukim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = srcs/game_main/utils.c srcs/key/key_event.c srcs/key/key_state_update.c	\
srcs/character/character_movement.c srcs/character/draw_character.c 			\
srcs/character/character_y_movement_check.c 									\
srcs/drawing/draw_map.c srcs/drawing/draw_next_frame.c 							\
srcs/drawing/drawing_function.c srcs/drawing/redraw_map.c srcs/game_main/game.c	\
srcs/game_main/movement_count.c srcs/game_main/set_ptr.c 						\
srcs/game_main/setting.c srcs/game_main/collectible.c 							\
srcs/map_check/check_player.c srcs/map_check/check_route.c						\
srcs/map_check/check_valid_path.c srcs/map_check/draw_trajectory.c				\
srcs/map_check/fallable.c srcs/map_check/jumpable.c srcs/map_check/lst_item.c 	\
srcs/map_check/make_graph.c srcs/map_check/simul_utils.c 						\
srcs/map_check/walkable.c srcs/map_file/check_map.c 							\
srcs/map_check/down_jumpable.c srcs/map_file/read_mapfile.c						\
srcs/map_check/check_graph.c srcs/map_check/checker.c srcs/map_check/simulate.c \
srcs/monster/gen_monster.c srcs/monster/monster_movement.c						
BONUSFILES = srcs_bonus/character/character_movement_bonus.c 					\
srcs_bonus/character/draw_character_bonus.c srcs_bonus/drawing/draw_map_bonus.c \
srcs_bonus/character/character_y_movement_check_bonus.c 						\
srcs_bonus/game_main/collectible_bonus.c										\
srcs_bonus/map_check/down_jumpable_bonus.c										\
srcs_bonus/drawing/draw_next_frame_bonus.c 										\
srcs_bonus/drawing/drawing_function_bonus.c 									\
srcs_bonus/drawing/redraw_map_bonus.c srcs_bonus/map_check/simulate_bonus.c		\
srcs_bonus/map_check/check_graph_bonus.c srcs_bonus/map_check/checker_bonus.c 	\
srcs_bonus/game_main/game_bonus.c srcs_bonus/game_main/movement_count_bonus.c 	\
srcs_bonus/game_main/set_ptr_bonus.c srcs_bonus/game_main/setting_bonus.c 		\
srcs_bonus/game_main/utils_bonus.c srcs_bonus/key/key_event_bonus.c 			\
srcs_bonus/key/key_state_update_bonus.c 										\
srcs_bonus/map_check/check_player_bonus.c										\
srcs_bonus/map_check/check_route_bonus.c 										\
srcs_bonus/map_check/check_valid_path_bonus.c 									\
srcs_bonus/map_check/draw_trajectory_bonus.c 									\
srcs_bonus/map_check/fallable_bonus.c srcs_bonus/map_check/jumpable_bonus.c 	\
srcs_bonus/map_check/lst_item_bonus.c srcs_bonus/map_check/make_graph_bonus.c 	\
srcs_bonus/map_check/simul_utils_bonus.c srcs_bonus/map_check/walkable_bonus.c 	\
srcs_bonus/map_file/check_map_bonus.c srcs_bonus/map_file/read_mapfile_bonus.c 	\
srcs_bonus/monster/gen_monster_bonus.c 											\
srcs_bonus/monster/monster_movement_bonus.c										
BONUSOBJS = $(BONUSFILES:.c=.o)
OBJS = $(FILES:.c=.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror
NAME = so_long
LIBFT = libft.a
LIB = ./libft/libft.a
MLX_B = libmlx.dylib

ifdef WITH_BONUS
	OBJECTS = $(BONUSOBJS)
else
	OBJECTS = $(OBJS)
endif

.PHONY : clean bonus all fclean re

all : $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) 
	cp $(LIB) $(LIBFT)
	$(CC) -o $(NAME) $(CCFLAGS) $(OBJECTS) $(LIBFT) -L. -lmlx -lft -framework OpenGL -framework Appkit

$(LIBFT) : 
	make bonus -C ./libft

bonus :
	make WITH_BONUS=1 all

%.o : %.c
	$(CC) $(CCFLAGS) -c  -o $@ $<

clean :
	make -C ./libft fclean
	rm -f $(OBJS) $(BONUSOBJS) $(LIBFT)

fclean : clean
	rm -f $(NAME)

re : fclean all
