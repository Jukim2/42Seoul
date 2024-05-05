/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:02:03 by junseo            #+#    #+#             */
/*   Updated: 2023/02/03 19:47:12 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "mlx.h"

int	key_down(int keycode, t_game *game)
{
	key_state_update(keycode, game);
	return (1);
}

int	key_up(int keycode, t_game *game)
{
	if (keycode == game->key)
		game->key = KEY_LEAVE;
	return (1);
}

int	cont(t_game *game)
{
	static int	delay;
	int			dx;
	int			dy;

	if (delay++ % 2 != 0)
		return (1);
	dy = cal_y_displacement(game, cal_y_speed(game));
	game->c.y += dy;
	dx = cal_x_displacement(game, game->key);
	game->c.x += dx;
	if (game->c.x > (20) * 119 || game->c.y > (10) * 130)
	{
		ft_printf("Map Size should be in standard... plz..\n");
		exit(0);
	}
	if (meet_monster(game))
	{
		ft_printf("Watch out! Monster!\n");
		exit(0);
	}
	move_monster(game);
	collect_item(game);
	draw_next_frame(game);
	count_movement(game, dx, dy);
	return (1);
}
