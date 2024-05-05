/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:28:37 by jukim2            #+#    #+#             */
/*   Updated: 2022/12/05 19:05:54 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "ft_printf_bonus.h"

int	match_print(va_list ap, char type, t_option *op)
{
	int	val;

	val = 0;
	if (type == 'd' || type == 'i')
		val = print_d(ap, op);
	else if (type == 'u')
		val = print_u(ap, op);
	else if (type == 'x')
		val = print_x(ap, op);
	else if (type == 'X')
		val = print_bigx(ap, op);
	else if (type == 'c')
		val = print_c(ap, op);
	else if (type == 's')
		val = print_s(ap, op);
	else if (type == 'p')
		val = print_p(ap, op);
	else if (type == '%')
		val = print_percent(op);
	if (val == -1)
	{
		free (op);
		return (-1);
	}
	return (val);
}

char	check_option(const char **str, t_option *op)
{
	char	*specifiers;

	specifiers = "spdiuxcX%%";
	while (is_option(**str))
		flag_check(*((*str)++), op);
	while (ft_isdigit(**str))
		width_check(*((*str)++), &(op->min));
	if (**str == '.')
	{
		(*str)++;
		op->dotted = 1;
	}
	while (ft_isdigit(**str))
		precision_check(*((*str)++), &(op->precision));
	if (ft_strchr(specifiers, **str))
	{
		op->specifier = **str;
		return (*((*str)++));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	t_option	*op;
	va_list		ap;
	int			cnt;
	int			printed_ch;

	cnt = 0;
	op = ft_calloc(1, sizeof(t_option));
	if (!op)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && str++)
		{
			printed_ch = (match_print(ap, check_option(&str, op), op));
			if (printed_ch == -1)
				return (-1);
			cnt += printed_ch;
			ft_bzero(op, sizeof(t_option));
		}
		if (*str && *str != '%' && write(1, str++, 1))
			cnt++;
	}
	free(op);
	return (cnt);
}
