/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_jumpable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:29:47 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/01 15:21:12 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	is_down_jumpable(t_game *game, char **checker, int x, int y)
{
	int			g_idx;
	int			y_idx;
	const int	x_idx = game->x / BLOCK;

	g_idx = find_ground(game, game->x, game->y + BLOCK);
	y_idx = game->y / BLOCK;
	if (x_idx != x / BLOCK || g_idx - 1 != y / BLOCK \
	|| g_idx == 0 || y_idx == g_idx - 1)
		return (0);
	while (++y_idx < g_idx - 1)
	{
		if (game->map.str[y_idx][x_idx] != WALL)
			checker[y_idx][x_idx] = '2';
	}
	checker[y_idx][x_idx] = '1';
	return (1);
}
