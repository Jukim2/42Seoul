/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jumpable_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:24:05 by jukim2            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "mlx.h"

int	is_jumpable_ground(t_game *game, char **checker, int x, int y)
{
	const int	x_store = game->x / BLOCK;
	const int	y_store = game->y / BLOCK;

	if (x < game->x)
	{
		if (is_l_jumpable(game, checker, x, y))
			return (1);
		if (update(game, x_store, y_store) \
		&& is_ll_jumpable(game, checker, x, y))
			return (1);
	}
	if (x > game->x)
	{
		if (is_r_jumpable(game, checker, x, y))
			return (1);
		if (update(game, x_store, y_store) \
		&& is_rr_jumpable(game, checker, x, y))
			return (1);
	}
	return (0);
}

int	is_r_jumpable(t_game *game, char **checker, int x, int y)
{
	int	t;

	t = 0;
	if (!is_wall_s(game, BLOCK - 1, 0))
		game->x += (BLOCK - 1);
	simulate(game, &t, RIGHT);
	while (cal_possible_y_fall(game))
	{
		check_reachable_space(game, checker);
		simulate(game, &t, RIGHT);
	}
	return (game->x + (CHARACTER_W - 1) >= x && game->y == y);
}

int	is_rr_jumpable(t_game *game, char **checker, int x, int y)
{
	int	t;

	t = 0;
	simulate(game, &t, RIGHT);
	while (cal_possible_y_fall(game))
	{
		check_reachable_space(game, checker);
		simulate(game, &t, RIGHT);
	}
	return (game->x + (CHARACTER_W - 1) >= x && game->y == y);
}

int	is_l_jumpable(t_game *game, char **checker, int x, int y)
{
	int	t;

	t = 0;
	if (!is_wall_s(game, CHARACTER_W -1, 0))
		game->x -= (CHARACTER_W - 1);
	simulate(game, &t, LEFT);
	while (cal_possible_y_fall(game))
	{
		check_reachable_space(game, checker);
		simulate(game, &t, LEFT);
	}
	return (game->x <= x + (BLOCK - 1) && game->y == y);
}

int	is_ll_jumpable(t_game *game, char **checker, int x, int y)
{
	int	t;

	t = 0;
	simulate(game, &t, LEFT);
	while (cal_possible_y_fall(game))
	{
		check_reachable_space(game, checker);
		simulate(game, &t, LEFT);
	}
	return (game->x <= x + (BLOCK - 1) && game->y == y);
}
