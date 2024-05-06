/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:02:06 by junseo            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

void	redraw_map(t_game *game, int x, int y)
{
	int	x_idx;
	int	y_idx;
	int	i;
	int	j;

	redraw_background(game, x, y);
	x_idx = x / BLOCK;
	y_idx = y / BLOCK;
	i = -5;
	while (i < 6)
	{
		j = 4;
		while (j > -5)
		{
			redraw_symbol(game, x_idx + i, y_idx + j);
			j--;
		}
		i++;
	}
}

void	redraw_background(t_game *game, int x, int y)
{
	int	i;
	int	x_idx;
	int	y_idx;
	int	answ;

	x_idx = x / 119;
	y_idx = y / 130;
	if (y_idx > 10)
		return ;
	answ = y_idx * 20 + x_idx;
	i = -2;
	while (++i < 2)
	{
		if (answ + i >= 0 && x_idx + i < 20 && x_idx + i > -1)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->map.ptrs[answ + i], (x_idx + i) * 119, 130 * y_idx);
		if (answ + i + 20 < 200 && x_idx + i < 20 && x_idx + i > -1)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->map.ptrs[answ + i + 20], (x_idx + i) * 119, \
			130 * (y_idx + 1));
		if (answ + i - 20 >= 0 && x_idx + i < 20 && x_idx + i > -1)
			mlx_put_image_to_window(game->mlx, game->win, \
			game->map.ptrs[answ + i - 20], (x_idx + i) * 119, \
			130 * (y_idx - 1));
	}
}

void	redraw_symbol(t_game *game, int x_idx, int y_idx)
{	
	char	ch;

	if (y_idx < 0 || x_idx < 0
		|| x_idx > game->map.w - 1 || y_idx >= game->map.h)
		return ;
	ch = game->map.str[y_idx][x_idx];
	if (ch == WALL)
		draw_ground(game, x_idx, y_idx);
	if (ch == COLLECTIBLE)
		draw_collectible(game, x_idx, y_idx);
	if (ch == EXIT)
		draw_exit(game, x_idx, y_idx);
	if (ch == PLAYER)
		draw_character(game, x_idx, y_idx);
}
