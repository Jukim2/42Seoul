/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fallable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:13:53 by jukim2            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

int	is_fallable_ground(t_game *game, char **checker, int x, int y)
{
	int	end;

	end = is_end(game);
	if (y <= game->y
		|| game->map.str[y / BLOCK - 1][x / BLOCK] == '1')
		return (0);
	if (end == 0)
		return (0);
	if (end == 2 && x < game->x)
		return (is_l_fallable(game, checker, x, y));
	if (end == 2 && x > game->x)
		return (is_r_fallable(game, checker, x, y));
	if (end == -1 && x < game->x)
		return (is_l_fallable(game, checker, x, y));
	if (end == 1 && game->x < x)
		return (is_r_fallable(game, checker, x, y));
	return (0);
}

int	is_l_fallable(t_game *game, char **checker, int x, int y)
{
	int		t;

	t = 17;
	if (!is_wall_s(game, -CHARACTER_W, 0))
		game->x -= CHARACTER_W;
	simulate(game, &t, LEFT);
	while (cal_possible_y_fall(game))
	{
		check_reachable_space(game, checker);
		simulate(game, &t, LEFT);
		if (x / BLOCK == (game->x) / BLOCK)
			foot(game, checker);
	}
	return ((game->x) / BLOCK == x / BLOCK && y == game->y);
}

int	is_r_fallable(t_game *game, char **checker, int x, int y)
{
	int		t;

	t = 17;
	if (!is_wall_s(game, BLOCK, 0))
		game->x += BLOCK;
	simulate(game, &t, RIGHT);
	while (cal_possible_y_fall(game))
	{
		check_reachable_space(game, checker);
		simulate(game, &t, RIGHT);
		if (x / BLOCK == (game->x + (CHARACTER_W - 1)) / BLOCK)
			foot(game, checker);
	}
	return (((game->x + (CHARACTER_W - 1)) / BLOCK)
		== (x / BLOCK) && y == game->y);
}

int	is_end(t_game *game)
{
	if (!is_wall_s(game, BLOCK, 0) && !is_wall_s(game, BLOCK, BLOCK)
		&& !is_wall_s(game, -BLOCK, 0) && !is_wall_s(game, -BLOCK, BLOCK))
		return (2);
	if (!is_wall_s(game, BLOCK, 0) && !is_wall_s(game, BLOCK, BLOCK))
		return (1);
	if (!is_wall_s(game, -BLOCK, 0) && !is_wall_s(game, -BLOCK, BLOCK))
		return (-1);
	return (0);
}
