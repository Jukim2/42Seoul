/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_graph_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:30:46 by kjs               #+#    #+#             */
/*   Updated: 2023/02/03 19:45:55 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_bonus.h"
#include "mlx.h"

void	make_graph(t_game *game, t_item *items, t_graph **graph)
{
	int		x_idx;
	int		y_idx;
	int		c_y_idx;
	char	**checker;

	y_idx = 0;
	fill_items(game, items, graph);
	while (++y_idx < game->map.h - 1)
	{
		x_idx = 0;
		while (++x_idx < game->map.w - 1)
		{
			if (game->map.str[y_idx][x_idx] == COLLECTIBLE)
			{
				checker = make_checker(game);
				c_y_idx = y_idx;
				move_position(game, checker, &x_idx, &c_y_idx);
				check_route(x_idx, c_y_idx, checker, game);
				insert_v(checker, game, items, \
				graph[item_idx(game, items, y_idx, x_idx)]);
				free_checker(game, checker);
			}
		}
	}
}

void	fill_items(t_game *game, t_item *items, t_graph **graph)
{
	int		idx;
	int		x_idx;
	int		y_idx;

	idx = 0;
	y_idx = 0;
	while (game->map.str[++y_idx])
	{
		x_idx = 0;
		while (game->map.str[y_idx][++x_idx])
		{
			if (game->map.str[y_idx][x_idx] == COLLECTIBLE)
			{
				items[idx] = make_item(idx, x_idx, y_idx);
				graph[idx] = ft_lstnew_item(idx);
				idx++;
			}
		}
	}
}

t_item	make_item(int idx, int x_idx, int y_idx)
{
	t_item	item;

	item.idx = idx;
	item.x_idx = x_idx;
	item.y_idx = y_idx;
	return (item);
}

void	insert_v(char **checker, t_game *game, t_item *items, t_graph *node)
{
	int	i;

	i = 0;
	while (i < game->item)
	{
		if (checker[items[i].y_idx][items[i].x_idx]
			&& items[i].idx != node->idx)
			ft_lstadd_item(&node, ft_lstnew_item(i));
		i++;
	}
}

int	item_idx(t_game *game, t_item *items, int y_idx, int x_idx)
{
	int	i;

	i = 0;
	while (i < game->item)
	{
		if (items[i].x_idx == x_idx && items[i].y_idx == y_idx)
			return (i);
		i++;
	}
	return (-1);
}
