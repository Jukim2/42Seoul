/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:29:31 by junseo            #+#    #+#             */
/*   Updated: 2023/01/30 11:31:22 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "mlx.h"

void	count_movement(int dx, int dy)
{
	static int	cnt;

	if (dx != 0 || dy != 0)
		cnt++;
	ft_printf("Movement count : %d\n", cnt);
}
