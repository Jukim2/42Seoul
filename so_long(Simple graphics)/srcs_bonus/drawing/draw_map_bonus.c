/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:33:15 by junseo            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "mlx.h"

void	draw_map(t_game *game)
{
	draw_background(game, 0, 0);
	draw_symbol(game, 0, 0);
}

void	draw_background(t_game *game, int x_idx, int y_idx)
{
	int	x;
	int	y;

	while (y_idx < game->map.h)
	{	
		if (x_idx == game->map.w)
		{
			x_idx = 0;
			y_idx++;
			continue ;
		}
		x = (x_idx * BLOCK) / 119;
		y = (y_idx * BLOCK / 130);
		if (x + y * 20 < 200)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->map.ptrs[x + y * 20], x * 119, y * 130);
		x_idx++;
	}
}

void	draw_symbol(t_game *game, int x_idx, int y_idx)
{
	while (y_idx < game->map.h)
	{	
		if (x_idx == game->map.w)
		{
			x_idx = 0;
			y_idx++;
			continue ;
		}
		redraw_symbol(game, x_idx, y_idx);
		x_idx++;
	}
}
