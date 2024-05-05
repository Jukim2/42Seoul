/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:48:29 by jukim2            #+#    #+#             */
/*   Updated: 2023/08/20 16:38:45 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"
#include <stdlib.h>

char	*ft_strfjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	if (s2)
		free(s2);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s && s[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}

int	get_len(int n)
{
	long long	num;
	int			len;

	len = 0;
	num = n;
	if (n < 0)
	{
		num *= -1;
		len++;
	}
	while (num >= 0)
	{
		num /= 10;
		len++;
		if (num == 0)
			break ;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	long long	num;

	len = get_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	num = n;
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
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
