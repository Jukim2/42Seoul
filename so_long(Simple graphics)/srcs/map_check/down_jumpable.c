/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_jumpable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:29:47 by jukim2            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
