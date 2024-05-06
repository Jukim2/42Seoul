/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:49:29 by jukim2            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

void	check_route(int x_idx, int y_idx, char **checker, t_game *game)
{
	int	map_x;
	int	map_y;

	checker[y_idx][x_idx] = '1';
	map_y = y_idx - 2;
	while (++map_y < game->map.h - 1)
	{
		map_x = 0;
		while (++map_x < game->map.w - 1)
		{
			if ((game->map.str[map_y + 1][map_x] != WALL \
			|| game->map.str[map_y][map_x] == WALL))
				continue ;
			if ((update(game, x_idx, y_idx) \
			&& is_fallable_ground(game, checker, map_x * BLOCK, map_y * BLOCK))
				|| (update(game, x_idx, y_idx) \
			&& is_down_jumpable(game, checker, map_x * BLOCK, map_y * BLOCK)))
				check_route(map_x, map_y, checker, game);
			if ((checker[map_y][map_x] != '1' && update(game, x_idx, y_idx) \
			&& is_walkable_ground(game, checker, map_x * BLOCK, map_y * BLOCK))
			|| (checker[map_y][map_x] != '1' && update(game, x_idx, y_idx) \
			&& is_jumpable_ground(game, checker, map_x * BLOCK, map_y * BLOCK)))
				check_route(map_x, map_y, checker, game);
		}
	}
}
