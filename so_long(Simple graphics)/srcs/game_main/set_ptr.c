/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:40:52 by jukim2            #+#    #+#             */
/*   Updated: 2023/01/30 10:55:02 by jukim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "mlx.h"

void	set_num_ptr(t_game *game)
{
	game->num.ptrs[0] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/0.xpm", &game->num.w, &game->num.h);
	game->num.ptrs[1] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/1.xpm", &game->num.w, &game->num.h);
	game->num.ptrs[2] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/2.xpm", &game->num.w, &game->num.h);
	game->num.ptrs[3] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/3.xpm", &game->num.w, &game->num.h);
	game->num.ptrs[4] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/4.xpm", &game->num.w, &game->num.h);
	game->num.ptrs[5] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/5.xpm", &game->num.w, &game->num.h);
	game->num.ptrs[6] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/6.xpm", &game->num.w, &game->num.h);
	game->num.ptrs[7] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/7.xpm", &game->num.w, &game->num.h);
	game->num.ptrs[8] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/8.xpm", &game->num.w, &game->num.h);
	game->num.ptrs[9] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/9.xpm", &game->num.w, &game->num.h);
}

void	set_character_move_ptr(t_game *game)
{
	game->c.ptrs[10] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/left_walk1.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[11] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/right_walk1.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[12] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/left_walk2.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[13] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/right_walk2.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[14] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/left_walk3.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[15] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/right_walk3.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[16] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/left_walk4.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[17] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/right_walk4.xpm", &game->c.w, &game->c.h);
}

void	set_character_motion_ptr(t_game *game)
{
	game->c.ptrs[0] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/left_stand.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[1] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/right_stand.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[2] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/left_jump.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[3] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/right_jump.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[4] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/left_lie.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[5] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/right_lie.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[6] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/left_attack1.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[7] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/right_attack1.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[8] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/left_attack2.xpm", &game->c.w, &game->c.h);
	game->c.ptrs[9] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/right_attack2.xpm", &game->c.w, &game->c.h);
}

void	set_mon_move_ptr(t_game *game)
{
	game->m.ptrs[0] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/mon_left1.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[1] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/mon_right1.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[2] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/mon_left2.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[3] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/mon_right2.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[4] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/mon_left3.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[5] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/mon_right3.xpm", &game->m.w, &game->m.h);
}

void	set_mon_death_ptr(t_game *game)
{
	game->m.ptrs[6] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/m_l_death1.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[7] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/m_r_death1.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[8] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/m_l_death2.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[9] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/m_r_death2.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[10] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/m_l_death3.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[11] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/m_r_death3.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[12] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/m_l_death4.xpm", &game->m.w, &game->m.h);
	game->m.ptrs[13] = mlx_xpm_file_to_image(game->mlx, \
	"./maple_img/m_r_death4.xpm", &game->m.w, &game->m.h);
}
