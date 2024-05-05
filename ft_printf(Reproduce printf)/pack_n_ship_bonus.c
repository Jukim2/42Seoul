/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_n_ship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:05:01 by jukim2            #+#    #+#             */
/*   Updated: 2022/12/05 19:06:05 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft_bonus.h"

int	pack_n_ship(char *str, t_option *op, int sign_space)
{
	char	*content;
	int		space;

	space = allocation(op, &content, ft_strlen(str), sign_space);
	if (!content)
	{
		free(str);
		return (-1);
	}
	put_str(sign_space, content, str, op);
	put_sign(op, content);
	if (space == 0 && op->specifier == 'c')
		space = 1;
	write(1, content, space);
	free(str);
	free(content);
	return (space);
}

int	allocation(t_option *op, char **content, int len, int sign_space)
{
	int	space;

	space = max(len + sign_space, op->precision + sign_space, op->min);
	*content = ft_calloc(sizeof(char), (space + 1));
	if (!*content)
		return (-1);
	if (op->zero)
		ft_memset(*content, '0', space);
	else
		ft_memset(*content, ' ', space);
	return (space);
}

void	put_str(int sign_space, char *content, char *str, t_option *op)
{
	if ((*str == '0' || *str == '\0') && op->dotted && op->precision == 0
		&& is_num_specifier(op->specifier))
		return ;
	if ((op->minus && *content == '0') || !op->minus)
	{
		ft_memcpy(content + ft_strlen(content) - ft_strlen(str), str,
			sizeof(char) * ft_strlen(str));
		if (*str == '\0' && op->specifier == 'c' && ft_strlen(content))
			content[ft_strlen(content) - 1] = '\0';
	}
	else
	{
		ft_memcpy(content + sign_space, str, sizeof(char) * ft_strlen(str));
		if (*str == '\0' && op->specifier == 'c')
			content[sign_space] = '\0';
	}
}

void	put_sign(t_option *op, char *content)
{
	if (op->sign)
		signs(op, content, &(op->sign));
	if (op->zero_x)
		signs(op, content, op->zero_x);
}
