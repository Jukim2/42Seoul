/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_movement_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:39:42 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/03 19:45:55 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "mlx.h"

int	cal_x_displacement(t_game *game, char ch)
{
	int	dx;

	dx = 2;
	if (ch == LEFT)
	{
		while (is_wall(game, -dx, 0) || is_wall(game, -dx, CHARACTER_H - 1))
			dx--;
		return (ft_min(0, -dx));
	}
	if (ch == RIGHT)
	{
		while (is_wall(game, (CHARACTER_W - 1) + dx, 0)
			|| is_wall(game, (CHARACTER_W - 1) + dx, CHARACTER_H - 1))
			dx--;
		return (ft_max(0, dx));
	}
	return (0);
}

int	cal_y_speed(t_game *game)
{
	if (!game->is_jumping && is_on_ground(game))
		return (0);
	else if ((game->time == 0 && !game->is_jumping && !is_on_ground(game))
		|| (game->time == 0 && game->is_jumping == UNDER_JUMP))
		game->time = 15;
	return (-8 + ((++game->time) / 2));
}

int	cal_y_displacement(t_game *game, int speed)
{
	int	dy;

	dy = 15;
	if (game->is_jumping == UNDER_JUMP)
	{
		if (check_underjump_end(game))
		{
			game->is_jumping = FALLING;
			return (0);
		}
		return (cal_safe_dist(game, speed));
	}
	else if (speed <= 0)
		return (cal_jumping_dist(game, dy, speed));
	else
		return (cal_falling_dist(game, dy, speed));
}

int	meet_monster(t_game *game)
{
	int	dist;

	dist = game->m.x - game->c.x;
	if (game->m.life != ALIVE)
		return (0);
	if (game->m.face == L_FACE)
	{
		if (0 < dist && dist < CHARACTER_W && game->m.y == game->c.y)
			return (1);
	}
	if (game->m.face == R_FACE)
	{
		if (-CHARACTER_W < dist && dist < 0 && game->m.y == game->c.y)
			return (1);
	}
	return (0);
}
