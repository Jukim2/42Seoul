/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 02:15:27 by junseo            #+#    #+#             */
/*   Updated: 2023/02/01 14:28:15 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "mlx.h"

int	is_wall(t_game *game, int dx, int dy)
{
	int	x_idx;
	int	y_idx;

	x_idx = (game->c.x + dx) / BLOCK;
	y_idx = ((game->c.y + dy) / BLOCK);
	if (game->map.str[y_idx][x_idx] == WALL)
		return (1);
	return (0);
}

int	find_ground(t_game *game, int x, int y)
{
	int	x_idx;
	int	y_idx;

	x_idx = x / BLOCK;
	y_idx = y / BLOCK;
	while (++y_idx < game->map.h && game->map.str[y_idx][x_idx] == WALL)
	{
		if (y_idx == game->map.h - 1)
			return (0);
	}
	while (++y_idx < game->map.h && game->map.str[y_idx][x_idx] != WALL)
	{
		if (y_idx == game->map.h - 1)
			return (0);
	}
	return (y_idx);
}

int	is_on_ground(t_game *game)
{
	if (is_wall(game, 0, CHARACTER_H)
		|| is_wall(game, (CHARACTER_W - 1), CHARACTER_H))
		return (1);
	return (0);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a <= b)
		return (b);
	return (a);
}
