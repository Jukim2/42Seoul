/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:23:36 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/01 15:20:54 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

char	**make_checker(t_game *game)
{
	int		i;
	char	*str;
	char	**checker;

	i = 0;
	checker = ft_calloc(game->map.h + 1, sizeof(char *));
	while (i < game->map.h)
	{
		str = ft_calloc(game->map.w + 1, sizeof(char));
		checker[i++] = str;
	}
	checker[i] = 0;
	return (checker);
}

void	free_checker(t_game *game, char **checker)
{
	int	i;

	i = 0;
	while (i < game->map.h)
		free(checker[i++]);
	free(checker);
}

void	print_checker(t_game *game, char **checker)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.h - 1)
	{
		j = -1;
		while (++j < game->map.w - 1)
		{
			if (checker[i][j])
				put_square_pix(game, j, i);
		}
	}
}
