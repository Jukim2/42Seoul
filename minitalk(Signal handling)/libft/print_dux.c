/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:28:33 by jukim2            #+#    #+#             */
/*   Updated: 2023/01/30 11:14:48 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_d(va_list ap, t_option *op)
{
	int		num;
	char	*str;

	num = va_arg(ap, int);
	str = ft_pos_itoa(num);
	str = add_padding(str, op);
	if (!str)
		return (-1);
	sign_space(num, op);
	if (rule_apply(num, op) == 0)
	{
		free(str);
		return (0);
	}
	if (num == 0 && op->dotted && !op->precision)
		*str = '\0';
	return (pack_n_ship(str, op, sign_space(num, op)));
}

int	print_u(va_list ap, t_option *op)
{
	unsigned int	num;
	char			*str;

	num = va_arg(ap, int);
	str = ft_pos_itoa(num);
	str = add_padding(str, op);
	if (!str)
		return (-1);
	if (rule_apply(num, op) == 0)
	{
		free(str);
		return (0);
	}
	return (pack_n_ship(str, op, 0));
}

int	print_bigx(va_list ap, t_option *op)
{
	unsigned int	num;
	char			*str;

	num = (unsigned int)va_arg(ap, int);
	hex_str(num, &str);
	str = add_padding(str, op);
	if (!str)
		return (-1);
	if (rule_apply(num, op) == 0)
	{
		free(str);
		return (0);
	}
	return (pack_n_ship(upper(str), op, (2 * op->sharp)));
}

int	print_x(va_list ap, t_option *op)
{
	unsigned int	num;
	char			*str;

	num = (unsigned int)va_arg(ap, long long);
	hex_str(num, &str);
	str = add_padding(str, op);
	if (!str)
		return (-1);
	if (rule_apply(num, op) == 0)
	{
		free(str);
		return (0);
	}
	return (pack_n_ship(str, op, (2 * op->sharp)));
}

void	hex_str(long long num, char **str)
{
	char	*hex;
	int		store[16];
	int		i;
	int		j;

	i = 0;
	j = 0;
	hex = "0123456789abcdef";
	if (num < 0)
		num *= -1;
	while (num >= 0)
	{
		store[i] = num % 16;
		num = num / 16;
		i++;
		if (num == 0)
			break ;
	}
	(*str) = ft_calloc(i + 1, sizeof(char));
	if (!*str)
		return ;
	while (i)
		(*str)[j++] = *(hex + store[--i]);
}
