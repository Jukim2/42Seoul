/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:53:10 by jukim2            #+#    #+#             */
/*   Updated: 2022/12/05 19:06:37 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "ft_printf_bonus.h"

int	num_len(long long n)
{
	long long	num;
	int			len;

	len = 0;
	num = n;
	if (n < 0)
		num *= -1;
	while (num >= 0)
	{
		num /= 10;
		len++;
		if (num == 0)
			break ;
	}
	return (len);
}

char	*ft_pos_itoa(long long n)
{
	int			len;
	char		*str;
	long long	num;

	len = num_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	num = n;
	if (num < 0)
		num *= -1;
	str[len--] = '\0';
	while (num >= 0)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
		if (num == 0)
			break ;
	}
	return (str);
}

char	*add_padding(char *n, t_option *op)
{
	char	*padding;
	char	*joined;

	if (ft_strlen(n) < (size_t)op->precision)
	{
		padding = malloc(sizeof(char) * (op->precision - ft_strlen(n) + 1));
		if (!padding)
			return (0);
		ft_memset(padding, '0', (op->precision - ft_strlen(n)));
		padding[op->precision - ft_strlen(n)] = 0;
	}
	else
		return (n);
	joined = ft_strjoin(padding, n);
	if (!joined)
		return (0);
	free(padding);
	free(n);
	return (joined);
}

void	signs(t_option *op, char *str, char *sign)
{
	if (!sign)
		return ;
	if (op->minus && *str)
	{
		while (*sign)
			*(str++) = *(sign++);
		return ;
	}
	if (ft_isdigit(*str))
	{
		while (*sign)
		{
			*(str++) = *(sign++);
		}
		return ;
	}
	while (!ft_isalnum(*(str + ft_strlen(sign))) && *(str + ft_strlen(sign)))
		str++;
	while (*sign)
		*(str++) = *(sign++);
}

int	max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	return (c);
}
