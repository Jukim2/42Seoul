/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:45:00 by jukim2            #+#    #+#             */
/*   Updated: 2023/01/30 11:14:23 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_option(char ch)
{
	if (ch == '-' || ch == '+' || ch == '0' || ch == '#' || ch == ' ')
		return (1);
	return (0);
}

void	flag_check(char ch, t_option *op)
{
	if (ch == '-')
		op -> minus = 1;
	else if (ch == '+')
		op -> plus = 1;
	else if (ch == '0')
		op -> zero = 1;
	else if (ch == '#')
		op -> sharp = 1;
	else if (ch == ' ')
		op -> space = 1;
}

void	width_check(char ch, int *min_width)
{
	*min_width *= 10;
	*min_width += ch - '0';
}

void	precision_check(char ch, int *precision)
{
	*precision *= 10;
	*precision += ch - '0';
}
