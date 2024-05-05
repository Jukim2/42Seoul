/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:11:19 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:51:18 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_option
{
	int		min;
	int		precision;
	int		minus;
	int		zero;
	int		sharp;
	int		space;
	int		plus;
	char	sign;
	int		dotted;
	char	*zero_x;
	char	specifier;
}	t_option;

typedef struct s_file
{
	int				fd;
	struct s_line	*line;
	struct s_file	*next_file;
	struct s_file	*prev_file;
}	t_file;

typedef struct s_line
{
	char			*str;
	struct s_line	*next_line;
	struct s_line	*prev_line;
}	t_line;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				match_print(va_list ap, char type, t_option *op);
char			check_option(const char **str, t_option *op);
int				ft_printf(const char *str, ...);
int				is_option(char ch);
void			flag_check(char ch, t_option *op);
void			width_check(char ch, int *min_width);
void			precision_check(char ch, int *precision);
int				max(int a, int b, int c);
int				allocation(t_option *op, char **content, \
				int len, int sign_space);
void			put_str(int sign_space, char *content, char *str, t_option *op);
void			put_sign(t_option *op, char *content);
int				pack_n_ship(char *str, t_option *op, int sign_space);
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
int				sign_space(int num, t_option *op);
int				rule_apply(int num, t_option *op);
char			*upper(char	*str);
int				is_num_specifier(char ch);
t_file			*find_file(int fd, t_file *file_list);
int				make_line_node(t_file *file);
int				make_file_node(int fd, t_file **file_list);
int				find_newline(int idx, char *buffer);
char			*ft_strnjoin(char *str1, char *str2, \
				int start_idx, int end_idx);
char			*get_next_line(int fd);
char			*read_file(int fd, char *buffer, t_file *file);
int				make_line(int rbyte, t_line *current_line, char *buffer);
int				push_line(t_line *current_line, \
				char *buffer, int start, int end);
void			free_blf(char *buffer, t_line *line, \
				t_file *file, t_file **file_list);
char			*ft_strfjoin(char *s1, char *s2);
int				ft_isdigit(int s);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
unsigned int	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif