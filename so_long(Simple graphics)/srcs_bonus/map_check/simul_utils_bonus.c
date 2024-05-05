/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:56:14 by junseo            #+#    #+#             */
/*   Updated: 2023/02/03 19:45:55 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "../../includes/libft.h"
#include "mlx.h"

int	update(t_game *game, int x_idx, int y_idx)
{
	game->x = x_idx * BLOCK;
	game->y = y_idx * BLOCK;
	return (1);
}

void	foot(t_game *game, char **checker)
{
	while (cal_possible_y_fall(game))
	{
		check_reachable_space(game, checker);
		game->y += ft_min(3, cal_possible_y_fall(game));
	}
}

int	is_wall_s(t_game *game, int dx, int dy)
{
	int	x_idx;
	int	y_idx;

	x_idx = (game->x + dx) / BLOCK;
	y_idx = (game->y + dy) / BLOCK;
	if (game->map.str[y_idx][x_idx] == WALL)
		return (1);
	return (0);
}

int	cal_possible_y_fall(t_game *game)
{
	int	dy;

	dy = 15;
	while (is_wall_s(game, 0, CHARACTER_H - 1 + dy)
		|| is_wall_s(game, CHARACTER_W - 1, CHARACTER_H - 1 + dy))
	{
		if (--dy == 0)
			break ;
	}
	return (ft_max(0, dy));
}

void	check_reachable_space(t_game *game, char **checker)
{
	int	x_idx;
	int	y_idx;

	x_idx = game->x / BLOCK;
	y_idx = game->y / BLOCK;
	if (game->y <= y_idx * BLOCK + 48 && game->x <= x_idx * BLOCK + 48 \
	&& !checker[y_idx][x_idx])
		checker[y_idx][x_idx] = '2';
	if (game->y <= y_idx * BLOCK + 48 \
	&& game->x + (CHARACTER_W - 1) >= (x_idx + 1) * BLOCK + 16 \
	&& !checker[y_idx][x_idx + 1])
		checker[y_idx][x_idx + 1] = '2';
	if (game->y + (CHARACTER_H - 1) >= (y_idx + 1) * BLOCK + 16 \
	&& game->x <= x_idx * BLOCK + 48 && !checker[y_idx + 1][x_idx])
		checker[y_idx + 1][x_idx] = '2';
	if (game->y + (CHARACTER_H - 1) >= (y_idx + 1) * BLOCK + 16 \
	&& game->x + (CHARACTER_W - 1) >= (x_idx + 1) * BLOCK + 16 \
	&& !checker[y_idx + 1][x_idx + 1])
		checker[y_idx + 1][x_idx + 1] = '2';
}
