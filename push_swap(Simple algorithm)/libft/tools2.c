/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:47:08 by jukim2            #+#    #+#             */
/*   Updated: 2023/01/30 11:14:55 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sign_space(int num, t_option *op)
{
	if (num < 0)
	{
		op->sign = '-';
		return (1);
	}
	if (op->plus || op->space)
	{
		if (op->plus)
			op->sign = '+';
		else
			op->sign = ' ';
		return (1);
	}
	return (0);
}

int	rule_apply(int num, t_option *op)
{	
	if (num < 0)
	{
		op->space = 0;
		op->plus = 0;
	}
	if (op->dotted)
		op->zero = 0;
	if (op->plus)
		op->space = 0;
	if (op->minus)
		op->zero = 0;
	if (op->sharp && num)
	{
		if (op->specifier == 'x')
			op->zero_x = "0x";
		else if (op->specifier == 'X')
			op->zero_x = "0X";
	}
	if (num == 0)
		op->sharp = 0;
	if (num == 0 && op->dotted && !op->precision
		&& !op->min && !op->plus && !op->space)
		return (0);
	return (1);
}

char	*upper(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int	is_num_specifier(char ch)
{
	if (ch == 'd' || ch == 'i' || ch == 'u' || ch == 'x' || ch == 'X')
		return (1);
	return (0);
}
