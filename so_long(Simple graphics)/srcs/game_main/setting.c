/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:38:32 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/01 15:20:04 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "mlx.h"

void	setting(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, BLOCK * game->map.w, \
								BLOCK * game->map.h, "game");
	if (!game->mlx || !game->win)
	{
		ft_printf("Error\nmlx ptr problem\n");
		exit (0);
	}
	set_img_ptr(game);
	set_map_ptr(game);
	set_character_motion_ptr(game);
	set_character_move_ptr(game);
	set_mon_death_ptr(game);
	set_mon_move_ptr(game);
	set_num_ptr(game);
}

void	set_map_ptr(t_game *game)
{
	int		i;
	char	*num;
	char	*file_name;
	char	*extension;

	i = 0;
	while (i < 200)
	{
		extension = malloc(sizeof(char) * 5);
		extension[0] = '.';
		extension[1] = 'x';
		extension[2] = 'p';
		extension[3] = 'm';
		extension[4] = '\0';
		num = ft_itoa(i + 1);
		file_name = ft_strjoin("./background/background", num);
		file_name = ft_strfjoin(file_name, extension);
		game->map.ptrs[i++] = mlx_xpm_file_to_image(game->mlx, \
							file_name, &game->map.unit_w, &game->map.unit_h);
		free(num);
		free(file_name);
	}
}

void	set_img_ptr(t_game *game)
{
	game->soil.ptr = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/maple_soil.xpm", &game->soil.w, &game->soil.h);
	game->grass.ptr = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/maple_grass.xpm", &game->grass.w, &game->grass.h);
	game->collectible.ptr = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/dollar.xpm", &game->collectible.w, &game->collectible.h);
	game->exit.ptr = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/portal.xpm", &game->exit.w, &game->exit.h);
}
