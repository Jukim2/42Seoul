/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: multi02 <multi02@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:11:07 by jukim2            #+#    #+#             */
/*   Updated: 2022/12/19 14:03:01 by multi02          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (str);
}
