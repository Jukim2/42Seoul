/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_next_frame_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:54:30 by junseo            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "mlx.h"

void	draw_next_frame(t_game *game)
{
	redraw_map(game, (game->map.w - 1) * BLOCK, 0);
	redraw_map(game, game->c.x, game->c.y);
	redraw_map(game, game->m.x, game->m.y);
	draw_character_motion(game);
	if (game->m.x && game->m.life == DEAD)
		draw_dying_monster(game);
	else if (game->m.life == ALIVE)
		draw_monster(game);
}
