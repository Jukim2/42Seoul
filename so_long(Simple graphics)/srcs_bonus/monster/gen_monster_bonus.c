/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_monster_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:28:14 by junseo            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "mlx.h"

void	find_genspot(t_game *game, char	**checker)
{
	int	y_idx;
	int	x_idx;
	int	cnt;

	y_idx = -1;
	x_idx = -1;
	cnt = 0;
	if (game->m.life == ALIVE)
		return ;
	while (checker[++y_idx])
	{
		while (++x_idx < game->map.w)
		{
			if (checker[y_idx][x_idx] == '1')
			{
				if ((++cnt == RAN_NUM))
					generate_monster(game, x_idx, y_idx);
			}
		}
		x_idx = -1;
	}
}

void	generate_monster(t_game *game, int x_idx, int y_idx)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->m.ptrs[0], x_idx * BLOCK, y_idx * BLOCK);
	game->m.life = ALIVE;
	game->m.x = x_idx * BLOCK;
	game->m.y = y_idx * BLOCK;
}
