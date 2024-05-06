/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_trajectory_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjs <kjs@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:19:42 by jukim2            #+#    #+#             */
/*   Updated: 2024/05/06 18:54:40 by kjs              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game_bonus.h"
#include "mlx.h"

void	put_pix(t_game *game, t_coord *content)
{
	mlx_pixel_put(game->mlx, game->win, content->x, content->y, 255);
}

void	put_square_pix(t_game *game, int x_idx, int y_idx)
{
	int	i;
	int	j;

	i = -2;
	j = -2;
	while (i++ < 5)
	{
		while (j++ < 5)
		{
			mlx_pixel_put(game->mlx, game->win, \
			x_idx * 64 + 30 + i, y_idx * 64 + 30 + j, 255);
		}
		j = -2;
	}
}

void	ft_lstiter_game(t_game *game, t_list *lst)
{
	if (lst == 0)
		return ;
	while (lst -> next != 0)
	{
		put_pix(game, lst -> content);
		lst = lst -> next;
	}
	put_pix(game, lst -> content);
}

t_list	*ft_lstnew_game(t_game *game, int dx)
{
	t_list	*n_node;
	t_coord	*coord;

	coord = malloc(sizeof(t_coord *));
	coord->x = game->x + dx;
	coord->y = game->y;
	n_node = malloc(sizeof(t_list));
	if (n_node == 0)
		return (0);
	n_node -> content = coord;
	n_node -> next = 0;
	return (n_node);
}
