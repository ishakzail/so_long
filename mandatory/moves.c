/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:05:40 by izail             #+#    #+#             */
/*   Updated: 2022/04/27 16:09:30 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_a(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "includes/assets/hero_left.xpm",
			&game->img_w, &game->img_h);
	move_player(game, 0, -1);
}

void	move_d(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "includes/assets/hero_right.xpm",
			&game->img_w, &game->img_h);
	move_player(game, 0, 1);
}

void	move_w(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "includes/assets/hero_up.xpm",
			&game->img_w, &game->img_h);
	move_player(game, -1, 0);
}

void	move_s(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "includes/assets/hero_down.xpm",
			&game->img_w, &game->img_h);
	move_player(game, 1, 0);
}
