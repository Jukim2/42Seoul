/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:48:39 by jukim2            #+#    #+#             */
/*   Updated: 2023/01/30 11:14:50 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	memory_transfer(unsigned long long int adrs, char **ptr_str)
{	
	char	*hex;
	int		store[16];
	int		i;
	int		j;

	i = 0;
	j = 2;
	hex = "0123456789abcdef";
	while (adrs > 0)
	{
		store[i] = adrs % 16;
		adrs = adrs / 16;
		i++;
	}
	(*ptr_str) = ft_calloc(i + 3, sizeof(char));
	if (!*ptr_str)
		return ;
	(*ptr_str)[0] = '0';
	(*ptr_str)[1] = 'x';
	while (i)
		(*ptr_str)[j++] = *(hex + store[i-- - 1]);
}

int	print_p(va_list ap, t_option *op)
{
	char	*ptr;
	char	*mem_str;

	ptr = (char *)va_arg(ap, void *);
	if (!ptr)
		mem_str = ft_strdup("0x0");
	else
		memory_transfer((unsigned long long)ptr, &mem_str);
	return (pack_n_ship(mem_str, op, 0));
}

int	print_c(va_list ap, t_option *op)
{
	char	*c;

	c = ft_calloc(2, sizeof(char));
	if (!c)
		return (-1);
	*c = va_arg(ap, int);
	return (pack_n_ship(c, op, 0));
}

int	print_s(va_list ap, t_option *op)
{
	char	*str;
	char	*str_dup;
	int		max_size;

	op->zero = 0;
	str = va_arg(ap, char *);
	if (!str)
	{
		max_size = 6;
		if (max_size > op->precision && op->dotted)
			max_size = op->precision;
		op->precision = 0;
		str_dup = ft_substr("(null)", 0, max_size);
	}
	else
	{
		max_size = ft_strlen(str);
		if (max_size > op->precision && op->dotted)
			max_size = op->precision;
		op->precision = 0;
		str_dup = ft_substr(str, 0, max_size);
	}
	if (!str_dup)
		return (-1);
	return (pack_n_ship(str_dup, op, 0));
}

int	print_percent(t_option *op)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (-1);
	*str = '%';
	add_padding(str, op);
	if (!str)
		return (-1);
	rule_apply(0, op);
	return (pack_n_ship(str, op, 0));
}
