/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_y_movement_check.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:08:25 by jukim2            #+#    #+#             */
/*   Updated: 2023/01/30 13:53:08 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "mlx.h"

int	cal_jumping_dist(t_game *game, int dy, int speed)
{
	while (is_wall(game, 0, -dy) || is_wall(game, (CHARACTER_W - 1), -dy))
	{
		dy--;
		if (dy == 0)
		{
			game->time = 17;
			break ;
		}
	}
	return (ft_max(speed, -dy));
}

int	cal_falling_dist(t_game *game, int dy, int speed)
{
	while (is_wall(game, 0, CHARACTER_H - 1 + dy)
		|| is_wall(game, (CHARACTER_W - 1), CHARACTER_H - 1 + dy))
	{
		dy--;
		if (dy == 0)
		{
			game->time = 0;
			game->is_jumping = 0;
			break ;
		}
	}
	return (ft_min(speed, dy));
}

int	check_underjump_end(t_game *game)
{
	static int	ground_check;

	if (is_wall(game, 0, 0))
		ground_check = 1;
	if (ground_check && !is_wall(game, 0, 0))
	{
		ground_check = 0;
		return (1);
	}
	return (0);
}

int	cal_safe_dist(t_game *game, int speed)
{
	if (is_wall(game, 0, 0) && !is_wall(game, 0, speed))
	{
		while (!is_wall(game, 0, speed))
			speed--;
		return (speed + 1);
	}
	return (speed);
}
