/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:41:20 by jukim2            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

void	simulate(t_game *game, int *t, int direction)
{
	int	dy;

	dy = -8 + ((++(*t)) / 2);
	game->y += cal_y_displacement_s(game, t, dy);
	game->x += cal_x_displacement_s(game, direction);
}

int	cal_x_displacement_s(t_game *game, int direction)
{
	int	dx;

	dx = 2;
	if (direction == LEFT)
	{
		while (dx && (is_wall_s(game, -dx, 0) \
		|| is_wall_s(game, -dx, CHARACTER_H - 1)))
			dx--;
		return (-dx);
	}
	if (direction == RIGHT)
	{
		while (dx && (is_wall_s(game, (CHARACTER_W - 1) + dx, 0) \
		|| is_wall_s(game, (CHARACTER_W - 1) + dx, CHARACTER_H - 1)))
			dx--;
		return (dx);
	}
	return (0);
}

int	cal_y_displacement_s(t_game *game, int *t, int speed)
{
	int	dy;

	dy = 15;
	if (speed <= 0)
	{
		while (dy && (is_wall_s(game, 0, -dy) \
		|| is_wall_s(game, (CHARACTER_W - 1), -dy)))
			dy--;
		if (dy == 0)
			*t = 17;
		return (ft_max(speed, -dy));
	}
	while (dy && (is_wall_s(game, 0, CHARACTER_H - 1 + dy) \
	|| is_wall_s(game, (CHARACTER_W - 1), CHARACTER_H - 1 + dy)))
		dy--;
	return (ft_min(speed, dy));
}
