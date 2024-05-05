/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:41:34 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/03 19:46:51 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H
# include "libft.h"
# define BLOCK 64
# define CHARACTER_W 39
# define CHARACTER_H 64
# define MON_W 64
# define MON_H 64
# define ATTACK_DELAY 20
# define ATTACK_DURATION 40
# define L_ATK_RANGE 100
# define R_ATK_RANGE 60
# define DEAD 0
# define ALIVE 1
# define END 2
# define LEFT 0
# define DOWN 1
# define UP 13
# define RIGHT 2
# define SPACE 49
# define Q 12
# define ESC 53
# define L_FACE 0
# define R_FACE 1
# define KEY_LEAVE -1
# define UPPER_JUMP 1
# define UNDER_JUMP -1 
# define FALLING 2
# define EMPTY '0'
# define WALL '1'
# define COLLECTIBLE '2'
# define PLAYER '3'
# define EXIT '4'
# define RAN_NUM 1
# define NUM_SIZE 32

typedef struct s_img
{
	int		w;
	int		h;
	int		x;
	int		y;
	void	*ptr;
}	t_img;

typedef struct s_coord
{
	int		x;
	int		y;
}	t_coord;

typedef struct s_item
{
	int				x_idx;
	int				y_idx;
	int				idx;
}	t_item;

typedef struct s_graph
{
	int				idx;
	struct s_graph	*next;
}	t_graph;

typedef struct s_character
{
	int		w;
	int		h;
	int		x;
	int		y;
	int		face;
	int		attack;
	int		life;
	void	*ptrs[18];
}	t_character;

typedef struct s_monster
{
	int		w;
	int		h;
	int		x;
	int		y;
	int		face;
	int		life;
	void	*ptrs[14];
}	t_monster;

typedef struct s_num
{
	int		w;
	int		h;
	void	*ptrs[10];
}	t_num;

typedef struct s_map
{
	int		unit_w;
	int		unit_h;
	int		w;
	int		h;
	void	*ptrs[200];
	char	**str;
}	t_map;

typedef struct s_game
{
	int			x;
	int			y;
	int			time;
	int			is_jumping;
	int			item;
	void		*mlx;
	void		*win;
	int			key;
	t_map		map;
	t_num		num;
	t_character	c;
	t_monster	m;
	t_img		soil;
	t_img		chline;
	t_img		grass;
	t_img		collectible;
	t_img		background;
	t_img		exit;
}	t_game;

void	free_graph(t_game *game, t_item *items, t_graph **graph);
int		cal_x_displacement(t_game *game, char ch);
int		cal_y_speed(t_game *game);
int		cal_y_displacement(t_game *game, int speed);
int		meet_monster(t_game *game);
int		cal_jumping_dist(t_game *game, int dy, int speed);
int		cal_falling_dist(t_game *game, int dy, int speed);
int		check_underjump_end(t_game *game);
int		cal_safe_dist(t_game *game, int speed);
void	punch(t_game *game);
void	draw_character_motion(t_game *game);
void	draw_map(t_game *game);
void	draw_background(t_game *game, int x_idx, int y_idx);
void	draw_symbol(t_game *game, int x_idx, int y_idx);
void	draw_next_frame(t_game *game);
void	draw_ground(t_game *game, int x_idx, int y_idx);
void	draw_collectible(t_game *game, int x_idx, int y_idx);
void	draw_character(t_game *game, int x_idx, int y_idx);
void	draw_exit(t_game *game, int x_idx, int y_idx);
void	redraw_map(t_game *game, int x, int y);
void	redraw_background(t_game *game, int x, int y);
void	print_cnt(t_game *game, int cnt);
void	redraw_symbol(t_game *game, int x_idx, int y_idx);
int		is_collectible(t_game *game, int dx, int dy);
void	collect_item(t_game *game);
t_item	make_item(int idx, int x_idx, int y_idx);
void	fill_items(t_game *game, t_item *items, t_graph **graph);
void	count_movement(t_game *game, int dx, int dy);
int		get_len(int num, int digits[15]);
void	set_num_ptr(t_game *game);
void	set_character_move_ptr(t_game *game);
void	set_character_motion_ptr(t_game *game);
void	set_mon_move_ptr(t_game *game);
void	set_mon_death_ptr(t_game *game);
void	setting(t_game *game);
void	relocate_symbol(t_game *game);
void	move_symbol(t_game *game, int x_idx, int y_idx);
void	set_map_ptr(t_game *game);
void	set_img_ptr(t_game *game);
int		is_wall(t_game *game, int dx, int dy);
int		find_ground(t_game *game, int x, int y);
int		is_on_ground(t_game *game);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		key_down(int keycode, t_game *game);
int		key_up(int keycode, t_game *game);
int		cont(t_game *game);
void	key_state_update(int keycode, t_game *game);
void	key_state_attack(int keycode, t_game *game);
int		game_over(int keycode, t_game *game);
void	key_state_lr(int keycode, t_game *game);
void	key_state_updown(int keycode, t_game *game);
void	check_player(t_game *game);
void	check_beatable(t_game *game, char **checker);
void	check_route(int x_idx, int y_idx, char **checker, t_game *game);
int		update(t_game *game, int x_idx, int y_idx);
void	simulate(t_game *game, int *t, int direction);
int		cal_x_displacement_s(t_game *game, int direction);
int		cal_y_displacement_s(t_game *game, int *t, int speed);
void	check_valid_path(t_game *game);
int		dfs_check(int i, t_game *game, int *is_visit, t_graph **graph);
int		is_all_visited(int num, int *is_visit);
int		exit_reachable(int i, t_game *game);
void	check_graph(t_game *game, t_graph **graph);
int		is_down_jumpable(t_game *game, char **checker, int x, int y);
void	put_pix(t_game *game, t_coord *content);
void	put_square_pix(t_game *game, int x_idx, int y_idx);
int		is_fallable_ground(t_game *game, char **checker, int x, int y);
int		is_end(t_game *game);
void	check_reachable_space(t_game *game, char **checker);
void	free_checker(t_game *game, char **checker);
int		is_l_fallable(t_game *game, char **checker, int x, int y);
int		is_r_fallable(t_game *game, char **checker, int x, int y);
int		is_jumpable_ground(t_game *game, char **hecker, int x, int y);
int		is_r_jumpable(t_game *game, char **checker, int x, int y);
int		is_rr_jumpable(t_game *game, char **checker, int x, int y);
int		is_l_jumpable(t_game *game, char **checker, int x, int y);
int		is_ll_jumpable(t_game *game, char **checker, int x, int y);
t_graph	*ft_lstnew_item(int idx);
void	move_position(t_game *game, char **checker, int *x_idx, int *y_idx);
void	make_graph(t_game *game, t_item *items, t_graph **graph);
void	ft_lstadd_item(t_graph **lst, t_graph *new);
int		item_idx(t_game *game, t_item *items, int y_idx, int x_idx);
void	insert_v(char **checker, t_game *game, t_item *items, t_graph *node);
void	make_graph(t_game *game, t_item *items, t_graph **graph);
char	**make_checker(t_game *game);
int		is_right_end(t_game *game, int x, int y);
int		is_left_end(t_game *game, int x, int y);
void	foot(t_game *game, char **checker);
int		is_wall_s(t_game *game, int dx, int dy);
int		cal_possible_y_fall(t_game *game);
int		is_walkable_ground(t_game *game, char **checker, int x, int y);
int		check_mapfile(t_game *game);
int		is_wall_surrounded(char *line, int line_num, t_game *game);
int		check_symbol(t_game *game, char *line, int is_last);
void	substitute_ch(char *line);
int		file_name_error(char *map_file);
int		read_mapfile(char *map_file, t_game *game);
void	find_genspot(t_game *game, char **checker);
void	generate_monster(t_game *game, int x_idx, int y_idx);
void	draw_dying_monster(t_game *game);
void	move_monster(t_game *game);
void	draw_monster(t_game *game);
int		block_type_m(t_game *game, int dx, int dy, char ch);
int		cal_x_movement_m(t_game *game, char ch);
void	print_checker(t_game *game, char **checker);
#endif
