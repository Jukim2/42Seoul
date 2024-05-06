/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_function_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:51:35 by junseo            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "mlx.h"

void	draw_ground(t_game *game, int x_idx, int y_idx)
{
	if (y_idx != 0 && game->map.str[y_idx - 1][x_idx] != WALL)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->grass.ptr, x_idx * BLOCK, y_idx * BLOCK - 15);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->soil.ptr, x_idx * BLOCK, y_idx * BLOCK);
}

void	draw_collectible(t_game *game, int x_idx, int y_idx)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->collectible.ptr, x_idx * BLOCK + 15, y_idx * BLOCK + 15);
}

void	draw_character(t_game *game, int x_idx, int y_idx)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->c.ptrs[0], x_idx * BLOCK, y_idx * BLOCK);
	game->c.x = x_idx * BLOCK;
	game->c.y = y_idx * BLOCK;
	game->c.life = ALIVE;
	game->key = KEY_LEAVE;
}

void	draw_exit(t_game *game, int x_idx, int y_idx)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->exit.ptr, x_idx * BLOCK - 12, y_idx * BLOCK - 105);
	game->exit.x = x_idx;
	game->exit.y = y_idx;
}
