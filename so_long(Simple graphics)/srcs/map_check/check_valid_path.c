/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:52:20 by kjs               #+#    #+#             */
/*   Updated: 2023/02/01 15:14:45 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

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
