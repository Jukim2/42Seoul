/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_count_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:29:31 by junseo            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_bonus.h"
#include "mlx.h"

void	count_movement(t_game *game, int dx, int dy)
{
	static int	cnt;

	if (dx != 0 || dy != 0)
		cnt++;
	print_cnt(game, cnt);
}

int	get_len(int num, int digits[15])
{
	int	cnt;

	cnt = 0;
	while (num)
	{
		digits[cnt] = num % 10;
		cnt++;
		num /= 10;
	}
	return (cnt);
}

void	print_cnt(t_game *game, int cnt)
{
	int	x;
	int	len;
	int	digits[15];

	len = get_len(cnt, digits);
	while (--len > -1)
	{
		x = (game->map.w - 1) * BLOCK - (len) * NUM_SIZE;
		mlx_put_image_to_window(game->mlx, game->win, \
		game->num.ptrs[digits[len]], x, 0);
	}		
}
