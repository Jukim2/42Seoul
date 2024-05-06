/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:52:20 by kjs               #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_valid_path(t_game *game)
{
	t_item	*items;
	t_graph	**graph;

	check_player(game);
	items = ft_calloc(game->item, sizeof(t_item));
	graph = ft_calloc(game->item, sizeof(t_graph *));
	make_graph(game, items, graph);
	check_graph(game, graph);
	free_graph(game, items, graph);
}
