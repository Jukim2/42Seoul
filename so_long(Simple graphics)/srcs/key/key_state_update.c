/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_state_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:29:20 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/01 15:36:55 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "mlx.h"

void	key_state_update(int keycode, t_game *game)
{
	if (keycode == ESC)
		game_over(keycode, game);
	if (game->c.attack)
		return ;
	else if (keycode == Q)
		key_state_attack(keycode, game);
	else if (keycode == LEFT || keycode == RIGHT)
		key_state_lr(keycode, game);
	else if (keycode == UP || keycode == DOWN || keycode == SPACE)
		key_state_updown(keycode, game);
}

void	key_state_attack(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	game->c.attack = 1;
	game->key = KEY_LEAVE;
}

int	game_over(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	ft_printf("Clicked the cross button or pressed ESC\n");
	exit(0);
}

void	key_state_lr(int keycode, t_game *game)
{
	game->key = keycode;
	game->c.face = keycode / 2;
}

void	key_state_updown(int keycode, t_game *game)
{
	if (keycode == DOWN)
	{
		if (game->is_jumping == UPPER_JUMP || !is_on_ground(game))
			return ;
		else
			game->key = DOWN;
	}
	else if (keycode == SPACE && game->key == DOWN)
	{
		if (is_wall(game, 0, 64) && is_wall(game, 38, 64)
			&& find_ground(game, game->c.x, game->c.y))
			game->is_jumping = UNDER_JUMP;
	}	
	else if (keycode == UP || keycode == SPACE)
	{
		if (game->map.str[game->c.y / BLOCK][game->c.x / BLOCK]
			== EXIT && !game->item)
		{
			ft_printf("Game clear!\n");
			exit(0);
		}
		game->is_jumping = UPPER_JUMP;
	}
}
