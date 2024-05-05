/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:56:41 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/13 11:47:34 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	is_white_space(char ch)
{
	if (ch == ' ' || (8 < ch && ch < 14))
		return (1);
	return (0);
}

static int	word_count(const char *str)
{
	int	count;
	int	word_finder;

	count = 0;
	word_finder = 1;
	while (*str)
	{
		if (word_finder && !is_white_space(*str))
		{
			count++;
			word_finder = 0;
		}
		if (is_white_space(*str))
			word_finder = 1;
		str++;
	}
	return (count);
}

static char	*make_str(const char *str)
{
	int		len;
	int		idx;
	char	*word;

	len = 0;
	while (!is_white_space(str[len]) && str[len] != '\0')
		len++;
	word = (char *)malloc(sizeof(char) * len + sizeof(char));
	if (word == 0)
		return (0);
	idx = -1;
	while (++idx < len)
	{
		word[idx] = str[idx];
	}
	word[idx] = '\0';
	return (word);
}

static void	free_all(char **arr, int arr_idx)
{
	int	i;

	i = 0;
	while (i < arr_idx)
	{
		free(arr[i++]);
	}
	free(arr);
}

char	**ps_split(char const *str)
{
	int		word_finder;
	int		arr_idx;
	char	**arr;

	word_finder = 1;
	arr_idx = 0;
	if (word_count(str) == 0)
		return (0);
	arr = (char **)ft_calloc(word_count(str) + 1, sizeof(char *));
	while (*str)
	{
		if (word_finder-- == 1 && !is_white_space(*str))
		{
			arr[arr_idx] = make_str(str);
			if (arr[arr_idx++] == 0)
			{
				free_all(arr, arr_idx - 1);
				return (0);
			}
		}
		if (is_white_space(*str))
			word_finder = 1;
		str++;
	}
	return (arr);
}
