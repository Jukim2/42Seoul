/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:18:20 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/01 15:19:57 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "mlx.h"

void	check_item_up(t_game *game, int x_idx, int y_idx)
{
	if (game->map.str[y_idx][x_idx] == COLLECTIBLE \
	&& game->c.y <= y_idx * BLOCK + 48 && game->c.x <= x_idx * BLOCK + 48)
	{
		game->map.str[y_idx][x_idx] = '0';
		game->item--;
	}	
	if (game->map.str[y_idx][x_idx + 1] == COLLECTIBLE \
	&& game->c.y <= y_idx * BLOCK + 48 \
	&& game->c.x + (CHARACTER_W - 1) >= (x_idx + 1) * BLOCK + 16)
	{
		game->map.str[y_idx][x_idx + 1] = '0';
		game->item--;
	}	
}

void	check_item_down(t_game *game, int x_idx, int y_idx)
{
	if (game->map.str[y_idx + 1][x_idx] == COLLECTIBLE \
	&& game->c.y + (CHARACTER_H - 1) >= (y_idx + 1) * BLOCK + 16 \
	&& game->c.x <= x_idx * BLOCK + 48)
	{
			game->map.str[y_idx + 1][x_idx] = '0';
		game->item--;
	}	
	if (game->map.str[y_idx + 1][x_idx + 1] == COLLECTIBLE \
	&& game->c.y + (CHARACTER_H - 1) >= (y_idx + 1) * BLOCK + 16 \
	&& game->c.x + (CHARACTER_W - 1) >= (x_idx + 1) * BLOCK + 16)
	{
		game->map.str[y_idx + 1][x_idx + 1] = '0';
		game->item--;
	}
}

void	collect_item(t_game *game)
{
	int	x_idx;
	int	y_idx;

	x_idx = game->c.x / BLOCK;
	y_idx = game->c.y / BLOCK;
	check_item_up(game, x_idx, y_idx);
	check_item_down(game, x_idx, y_idx);
}
