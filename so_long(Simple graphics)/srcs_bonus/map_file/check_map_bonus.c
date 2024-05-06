/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:55:50 by jukim2            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_bonus.h"

int	check_mapfile(t_game *game)
{
	int		line_num;
	char	**map;

	line_num = 0;
	map = game->map.str;
	if (game->map.h > 21 || game->map.w > 38)
		return (0);
	while (*map)
	{
		if (!check_symbol(game, *map, line_num == game->map.h - 1)
			|| ft_strlen(*map) != (size_t)game->map.w
			|| !is_wall_surrounded(*map, line_num, game))
			return (0);
		map++;
		line_num++;
	}
	return (1);
}

int	is_wall_surrounded(char *line, int line_num, t_game *game)
{
	int	wall_cnt;
	int	idx;

	idx = 0;
	wall_cnt = 0;
	while (line[idx])
	{
		if (line[idx] == WALL)
			wall_cnt++;
		if ((idx == 0 || idx == game->map.w - 1) && line[idx] != WALL)
			return (0);
		idx++;
	}
	if (line_num == 0 || line_num == game->map.h - 1)
	{
		if (wall_cnt != game->map.w)
			return (0);
	}
	return (1);
}

int	check_symbol(t_game *game, char *line, int is_last)
{
	static int	player_cnt;
	static int	exit_cnt;

	while (*line)
	{
		if (*line == '3')
			player_cnt++;
		if (*line == '4')
			exit_cnt++;
		if (*line == '2')
			game->item++;
		if (*line < '0' || *line > '4')
			return (0);
		line++;
	}
	if (is_last && (exit_cnt != 1 || player_cnt != 1 || game->item == 0))
		return (0);
	return (1);
}
