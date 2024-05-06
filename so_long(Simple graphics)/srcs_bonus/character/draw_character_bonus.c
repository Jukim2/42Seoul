/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_character_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:34:19 by junseo            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "mlx.h"

void	punch(t_game *game)
{
	static int	i;

	i++;
	if (i < ATTACK_DELAY)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->c.ptrs[game->c.face + 6], game->c.x, game->c.y);
	else if (i < ATTACK_DURATION)
	{
		if ((game->c.face == L_FACE && game->c.x - game->m.x < L_ATK_RANGE)
			|| (game->c.face == R_FACE && game->m.x - game->c.x < R_ATK_RANGE))
		{
			if (game->m.y == game->c.y && game->m.life == ALIVE)
				game->m.life = DEAD;
		}	
		mlx_put_image_to_window(game->mlx, game->win, \
		game->c.ptrs[game->c.face + 8], game->c.x, game->c.y);
	}
	if (i == ATTACK_DURATION)
	{
		game->c.attack = 0;
		mlx_put_image_to_window(game->mlx, game->win, \
		game->c.ptrs[game->c.face], game->c.x, game->c.y);
		i = 0;
	}
}

void	draw_character_motion(t_game *game)
{
	static int	i;

	if (game->c.attack)
		punch(game);
	else if (game->is_jumping)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->c.ptrs[game->c.face + 2], game->c.x, game->c.y);
	else if (game->key == DOWN)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->c.ptrs[game->c.face + 4], game->c.x, game->c.y + 32);
	else if (game->key == KEY_LEAVE)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->c.ptrs[game->c.face], game->c.x, game->c.y);
	else
	{
		if (++i == 64)
			i = 0;
		mlx_put_image_to_window(game->mlx, game->win, \
		game->c.ptrs[game->c.face + 10 + 2 * (i / 16)], game->c.x, game->c.y);
	}
}
