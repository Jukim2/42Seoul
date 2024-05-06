/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:27:34 by jukim2            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_graph(t_game *game, t_graph **graph)
{	
	int		idx;
	int		*is_visit;

	idx = 0;
	is_visit = ft_calloc(game->item, sizeof(int));
	while (idx < game->item)
	{
		if (dfs_check(idx, game, is_visit, graph))
			break ;
		idx++;
	}
	if (idx == game->item)
	{
		ft_printf("Error\nNo Valid Path\n");
		exit(0);
	}
	free(is_visit);
}

int	dfs_check(int i, t_game *game, int *is_visit, t_graph **graph)
{
	t_graph	*node;

	node = graph[i];
	is_visit[i] = 1;
	if (is_all_visited(game->item, is_visit) && exit_reachable(i, game))
	{
		is_visit[0] = -1;
		return (1);
	}	
	while (node->next)
	{
		node = node->next;
		if (!is_visit[node->idx])
			dfs_check(node->idx, game, is_visit, graph);
		if (is_visit[0] == -1)
			return (1);
	}
	is_visit[i] = 0;
	return (0);
}

int	is_all_visited(int num, int *is_visit)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (!is_visit[i])
			return (0);
		i++;
	}
	return (1);
}

int	exit_reachable(int i, t_game *game)
{
	int		x_idx;
	int		y_idx;
	char	**checker;

	y_idx = 0;
	while (i != -1 && game->map.str[++y_idx])
	{
		x_idx = 0;
		while (i != -1 && game->map.str[y_idx][++x_idx])
		{
			if (game->map.str[y_idx][x_idx] == COLLECTIBLE)
				i--;
		}
	}
	checker = make_checker(game);
	check_route(x_idx, y_idx, checker, game);
	if (checker[game->exit.y][game->exit.x])
	{
		free_checker(game, checker);
		return (1);
	}
	free_checker(game, checker);
	return (0);
}

void	free_graph(t_game *game, t_item *items, t_graph **graph)
{
	int		i;
	t_graph	*p_node;
	t_graph	*n_node;

	i = 0;
	while (i < game->item)
	{
		p_node = graph[i];
		n_node = graph[i];
		while (n_node)
		{
			p_node = n_node;
			n_node = p_node->next;
			free(p_node);
		}
		i++;
	}
	free(items);
	free(graph);
}
