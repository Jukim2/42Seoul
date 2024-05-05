/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:30:48 by jukim2            #+#    #+#             */
/*   Updated: 2022/11/18 15:07:03 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>

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

int		match_print(va_list ap, char type, t_option *op);
char	check_option(const char **str, t_option *op);
int		ft_printf(const char *str, ...);
int		is_option(char ch);
void	flag_check(char ch, t_option *op);
void	width_check(char ch, int *min_width);
void	precision_check(char ch, int *precision);
int		max(int a, int b, int c);
int		allocation(t_option *op, char **content, int len, int sign_space);
void	put_str(int sign_space, char *content, char *str, t_option *op);
void	put_sign(t_option *op, char *content);
int		pack_n_ship(char *str, t_option *op, int sign_space);
int		print_d(va_list ap, t_option *op);
int		print_u(va_list ap, t_option *op);
int		print_bigx(va_list ap, t_option *op);
int		print_x(va_list ap, t_option *op);
void	hex_str(long long num, char **str);
void	memory_transfer(unsigned long long int adrs, char **ptr_str);
int		print_p(va_list ap, t_option *op);
int		print_c(va_list ap, t_option *op);
int		print_s(va_list ap, t_option *op);
int		print_percent(t_option *op);
int		num_len(long long n);
char	*ft_pos_itoa(long long n);
char	*add_padding(char *n, t_option *op);
void	signs(t_option *op, char *str, char *sign);
int		sign_space(int num, t_option *op);
int		rule_apply(int num, t_option *op);
char	*upper(char	*str);
int		is_num_specifier(char ch);

#endif