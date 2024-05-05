/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:41:34 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/21 09:09:11 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
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
# define RAN_NUM 100
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

/* ===============.=============== */


/* ===============./libft=============== */

int				is_option(char ch);
void			flag_check(char ch, t_option *op);
void			width_check(char ch, int *min_width);
void			precision_check(char ch, int *precision);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int s);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
int				match_print(va_list ap, char type, t_option *op);
char			check_option(const char **str, t_option *op);
int				ft_printf(const char *str, ...);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *str, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strfjoin(char *s1, char *s2);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
unsigned int	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*get_next_line(int fd);
char			*read_file(int fd, char *buf, t_file *file);
int				make_line(int rbyte, t_line *line, char *buf);
int				push_line(t_line *line, char *buf, int start, int end);
void			free_blf(char *buf, t_line *line, t_file *file, t_file **file_list);
t_file			*find_file(int fd, t_file *file_list);
int				make_file_node(int fd, t_file **file_list);
int				make_line_node(t_file *file);
int				find_newline(int idx, char *buffer);
char			*ft_strnjoin(char *str1, char *str2, int start_idx, int end_idx);
int				pack_n_ship(char *str, t_option *op, int sign_space);
int				allocation(t_option *op, char **content, int len, int sign_space);
void			put_str(int sign_space, char *content, char *str, t_option *op);
void			put_sign(t_option *op, char *content);
int				print_d(va_list ap, t_option *op);
int				print_u(va_list ap, t_option *op);
int				print_bigx(va_list ap, t_option *op);
int				print_x(va_list ap, t_option *op);
void			hex_str(long long num, char **str);
void			memory_transfer(unsigned long long int adrs, char **ptr_str);
int				print_p(va_list ap, t_option *op);
int				print_c(va_list ap, t_option *op);
int				print_s(va_list ap, t_option *op);
int				print_percent(t_option *op);
int				num_len(long long n);
char			*ft_pos_itoa(long long n);
char			*add_padding(char *n, t_option *op);
void			signs(t_option *op, char *str, char *sign);
int				max(int a, int b, int c);
int				sign_space(int num, t_option *op);
int				rule_apply(int num, t_option *op);
char			*upper(char	*str);
int				is_num_specifier(char ch);

/* ===============./srcs=============== */


/* ===============./srcs/character=============== */

int				cal_x_displacement(t_game *game, char ch);
int				cal_y_speed(t_game *game);
int				cal_y_displacement(t_game *game, int speed);
int				meet_monster(t_game *game);
int				cal_jumping_dist(t_game *game, int dy, int speed);
int				cal_falling_dist(t_game *game, int dy, int speed);
int				check_underjump_end(t_game *game);
int				cal_safe_dist(t_game *game, int speed);
void			punch(t_game *game);
void			draw_character_motion(t_game *game);

/* ===============./srcs/drawing=============== */

void			draw_map(t_game *game);
void			draw_background(t_game *game, int x_idx, int y_idx);
void			draw_symbol(t_game *game, int x_idx, int y_idx);
void			draw_next_frame(t_game *game);
void			draw_ground(t_game *game, int x_idx, int y_idx);
void			draw_collectible(t_game *game, int x_idx, int y_idx);
void			draw_character(t_game *game, int x_idx, int y_idx);
void			draw_exit(t_game *game, int x_idx, int y_idx);
void			redraw_map(t_game *game, int x, int y);
void			redraw_background(t_game *game, int x, int y);
void			redraw_symbol(t_game *game, int x_idx, int y_idx);

/* ===============./srcs/game_main=============== */

void			check_item_up(t_game *game, int x_idx, int y_idx);
void			check_item_down(t_game *game, int x_idx, int y_idx);
void			collect_item(t_game *game);
void			count_movement(int dx, int dy);
void			set_num_ptr(t_game *game);
void			set_character_move_ptr(t_game *game);
void			set_character_motion_ptr(t_game *game);
void			set_mon_move_ptr(t_game *game);
void			set_mon_death_ptr(t_game *game);
void			setting(t_game *game);
void			set_map_ptr(t_game *game);
void			set_img_ptr(t_game *game);
int				is_wall(t_game *game, int dx, int dy);
int				find_ground(t_game *game, int x, int y);
int				is_on_ground(t_game *game);
int				ft_min(int a, int b);
int				ft_max(int a, int b);

/* ===============./srcs/key=============== */

int				key_down(int keycode, t_game *game);
int				key_up(int keycode, t_game *game);
int				cont(t_game *game);
void			key_state_update(int keycode, t_game *game);
void			key_state_attack(int keycode, t_game *game);
int				game_over(int keycode, t_game *game);
void			key_state_lr(int keycode, t_game *game);
void			key_state_updown(int keycode, t_game *game);

/* ===============./srcs/map_check=============== */

void			check_graph(t_game *game, t_graph **graph);
int				dfs_check(int i, t_game *game, int *is_visit, t_graph **graph);
int				is_all_visited(int num, int *is_visit);
int				exit_reachable(int i, t_game *game);
void			free_graph(t_game *game, t_item *items, t_graph **graph);
void			check_player(t_game *game);
void			check_beatable(t_game *game, char **checker);
void			move_position(t_game *game, char **checker, int *x_idx, int *y_idx);
void			check_route(int x_idx, int y_idx, char **checker, t_game *game);
void			check_valid_path(t_game *game);
char			**make_checker(t_game *game);
void			free_checker(t_game *game, char **checker);
void			print_checker(t_game *game, char **checker);
int				is_down_jumpable(t_game *game, char **checker, int x, int y);
void			put_pix(t_game *game, t_coord *content);
void			put_square_pix(t_game *game, int x_idx, int y_idx);
void			ft_lstiter_game(t_game *game, t_list *lst);
t_list			*ft_lstnew_game(t_game *game, int dx);
int				is_fallable_ground(t_game *game, char **checker, int x, int y);
int				is_l_fallable(t_game *game, char **checker, int x, int y);
int				is_r_fallable(t_game *game, char **checker, int x, int y);
int				is_end(t_game *game);
int				is_jumpable_ground(t_game *game, char **checker, int x, int y);
int				is_r_jumpable(t_game *game, char **checker, int x, int y);
int				is_rr_jumpable(t_game *game, char **checker, int x, int y);
int				is_l_jumpable(t_game *game, char **checker, int x, int y);
int				is_ll_jumpable(t_game *game, char **checker, int x, int y);
t_graph			*ft_lstnew_item(int idx);
void			ft_lstadd_item(t_graph **lst, t_graph *new);
void			make_graph(t_game *game, t_item *items, t_graph **graph);
void			fill_items(t_game *game, t_item *items, t_graph **graph);
t_item			make_item(int idx, int x_idx, int y_idx);
void			insert_v(char **checker, t_game *game, t_item *items, t_graph *node);
int				item_idx(t_game *game, t_item *items, int y_idx, int x_idx);
int				update(t_game *game, int x_idx, int y_idx);
void			foot(t_game *game, char **checker);
int				is_wall_s(t_game *game, int dx, int dy);
int				cal_possible_y_fall(t_game *game);
void			check_reachable_space(t_game *game, char **checker);
void			simulate(t_game *game, int *t, int direction);
int				cal_x_displacement_s(t_game *game, int direction);
int				cal_y_displacement_s(t_game *game, int *t, int speed);
int				is_walkable_ground(t_game *game, char **checker, int x, int y);

/* ===============./srcs/map_file=============== */

int				check_mapfile(t_game *game);
int				is_wall_surrounded(char *line, int line_num, t_game *game);
int				check_symbol(t_game *game, char *line, int is_last);
void			substitute_ch(char *line);
int				file_name_error(char *map_file);
int				open_error(int fd);
int				check_empty(t_game *game, char *joined);
int				read_mapfile(char *map_file, t_game *game);

/* ===============./srcs/monster=============== */

void			find_genspot(t_game *game, char	**checker);
void			generate_monster(t_game *game, int x_idx, int y_idx);
void			draw_dying_monster(t_game *game);
void			move_monster(t_game *game);
void			draw_monster(t_game *game);
int				block_type_m(t_game *game, int dx, int dy, char ch);
int				cal_x_movement_m(t_game *game, char ch);

#endif
