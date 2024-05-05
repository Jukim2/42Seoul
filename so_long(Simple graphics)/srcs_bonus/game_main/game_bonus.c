/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:49:55 by kjs               #+#    #+#             */
/*   Updated: 2023/02/03 19:45:55 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "mlx.h"
#include "../../includes/game_bonus.h"

int	main(int argc, char *argv[])
{
	t_game		game;
	char		*map_file;

	if (argc != 2)
	{
		ft_printf("Error\nCheck Argument Please\n");
		return (0);
	}
	map_file = argv[1];
	ft_bzero(&game, sizeof(t_game));
	if (!read_mapfile(map_file, &game))
	{
		ft_printf("Error\nYou should check your map file\n");
		exit (0);
	}
	setting(&game);
	draw_map(&game);
	check_valid_path(&game);
	mlx_loop_hook(game.mlx, cont, &game);
	mlx_hook(game.win, 2, 0, key_down, &game);
	mlx_hook(game.win, 3, 0, key_up, &game);
	mlx_hook(game.win, 17, 0, game_over, &game);
	mlx_loop(game.mlx);
	return (0);
}
