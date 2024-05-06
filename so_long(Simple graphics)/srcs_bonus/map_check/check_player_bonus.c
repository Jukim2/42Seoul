/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:29:12 by jukim2            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"

void	check_player(t_game *game)
{
	char	**checker;
	int		x_idx;
	int		y_idx;

	x_idx = game->c.x / BLOCK;
	y_idx = game->c.y / BLOCK;
	game->map.str[y_idx][x_idx] = EMPTY;
	checker = make_checker(game);
	move_position(game, checker, &x_idx, &y_idx);
	check_route(x_idx, y_idx, checker, game);
	check_beatable(game, checker);
	find_genspot(game, checker);
	free_checker(game, checker);
}

void	check_beatable(t_game *game, char **checker)
{
	int		x_idx;
	int		y_idx;

	y_idx = 0;
	while (game->map.str[++y_idx])
	{
		x_idx = 0;
		while (game->map.str[y_idx][++x_idx])
		{
			if (game->map.str[y_idx][x_idx] == COLLECTIBLE ||
				game->map.str[y_idx][x_idx] == EXIT)
			{
				if (!checker[y_idx][x_idx])
				{
					ft_printf("Error\nItem or Exit unreachable\n");
					exit(0);
				}	
			}
		}
	}
}

void	move_position(t_game *game, char **checker, int *x_idx, int *y_idx)
{
	int	g_idx;

	g_idx = find_ground(game, (*x_idx) * BLOCK, ((*y_idx) - 1) * BLOCK);
	while (*y_idx != g_idx - 1)
	{
		checker[*y_idx][*x_idx] = '2';
		(*y_idx)++;
	}
	*y_idx = g_idx - 1;
}
