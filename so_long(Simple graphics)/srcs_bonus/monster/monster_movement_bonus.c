/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_movement_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:21:37 by jukim2            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "mlx.h"

void	draw_dying_monster(t_game *game)
{
	static int	i;

	if (++i < 20)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->m.ptrs[game->m.face + 6], game->m.x, game->m.y);
	}
	else if (i < 25)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->m.ptrs[game->m.face + 8 + 2], game->m.x, game->m.y);
	}
	else if (i < 30)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->m.ptrs[game->m.face + 10], game->m.x, game->m.y);
	}
	else if (i < 37)
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		game->m.ptrs[game->m.face + 12], game->m.x, game->m.y);
	}
	if (i > 37)
		game->m.life = END;
}

void	move_monster(t_game *game)
{
	int	dx;

	if (game->m.life != ALIVE)
		return ;
	dx = cal_x_movement_m(game, game->m.face);
	game->m.x += dx;
	if (dx == 0 && game->m.face == L_FACE)
		game->m.face = R_FACE;
	else if (dx == 0 && game->m.face == R_FACE)
		game->m.face = L_FACE;
}

void	draw_monster(t_game *game)
{
	static int	i;

	if (++i == 24)
		i = 0;
	mlx_put_image_to_window(game->mlx, game->win, \
	game->m.ptrs[game->m.face + 2 * (i / 8)], game->m.x, game->m.y);
}

int	block_type_m(t_game *game, int dx, int dy, char ch)
{
	int	x_idx;
	int	y_idx;

	x_idx = (game->m.x + dx) / BLOCK;
	y_idx = ((game->m.y + dy) / BLOCK);
	if (game->map.str[y_idx][x_idx] == ch)
		return (1);
	return (0);
}

int	cal_x_movement_m(t_game *game, char ch)
{
	int	dx;

	dx = 2;
	if (ch == L_FACE)
	{
		while (block_type_m(game, -dx, 0, '1') \
		|| block_type_m(game, -dx, MON_H - 1, '1') \
		|| !block_type_m(game, -dx, 64, '1'))
			dx--;
		return (-dx);
	}
	if (ch == R_FACE)
	{
		while (block_type_m(game, (MON_W - 1) + dx, 0, '1') \
		|| block_type_m(game, (MON_W - 1) + dx, MON_H - 1, '1') \
		|| !block_type_m(game, MON_W + dx, 64, '1'))
			dx--;
		return (dx);
	}
	return (0);
}
