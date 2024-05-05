/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mapfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:11:07 by jukim2            #+#    #+#             */
/*   Updated: 2023/02/03 19:56:58 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../../includes/libft.h"
#include "../../includes/game.h"

void	substitute_ch(char *line)
{
	if (!line)
		return ;
	while (*line)
	{
		if (*line == 'C')
			*line = COLLECTIBLE;
		if (*line == 'P')
			*line = PLAYER;
		if (*line == 'E')
			*line = EXIT;
		if (*line == '\n')
			break ;
		line++;
	}
}

int	file_name_error(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len < 5)
		return (1);
	if (map_file[len - 4] == '.'
		&& map_file[len - 3] == 'b'
		&& map_file[len - 2] == 'e'
		&& map_file[len - 1] == 'r')
		return (0);
	return (1);
}

int	open_error(int fd)
{
	if (fd < 3)
	{
		ft_printf("Error\n");
		perror("Can't open file");
		return (1);
	}
	return (0);
}

int	check_empty(t_game *game, char *joined)
{
	if (!joined)
		return (1);
	game->map.str = ft_split(joined, '\n');
	free(joined);
	if (!game->map.str)
		return (1);
	return (0);
}

int	read_mapfile(char *map_file, t_game *game)
{
	int		fd;
	char	*line;
	char	*joined;

	fd = open(map_file, O_RDONLY);
	if (file_name_error(map_file) || open_error(fd))
		return (0);
	joined = NULL;
	while (1)
	{
		line = get_next_line(fd);
		substitute_ch(line);
		if (!line)
			break ;
		game->map.w = ft_strlen(line) - 1;
		if (!game->map.w)
			break ;
		game->map.h += 1;
		joined = ft_strfjoin(joined, line);
	}
	if (check_empty(game, joined) || !check_mapfile(game))
		return (0);
	return (1);
}
