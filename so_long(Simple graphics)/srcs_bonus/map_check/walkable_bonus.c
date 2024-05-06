/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walkable_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:37:30 by kjs               #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "mlx.h"

int	is_walkable_ground(t_game *game, char **checker, int x, int y)
{
	int	i;

	i = 0;
	if (game->y != y)
		return (0);
	if (x - game->x == BLOCK && !is_wall_s(game, BLOCK, 0) \
	&& is_wall_s(game, BLOCK, BLOCK))
	{
		check_reachable_space(game, checker);
		return (1);
	}
	if (x - game->x == -BLOCK && !is_wall_s(game, -BLOCK, 0) \
	&& is_wall_s(game, -BLOCK, BLOCK))
	{
		check_reachable_space(game, checker);
		return (1);
	}
	return (0);
}
