/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:16:28 by izail             #+#    #+#             */
/*   Updated: 2022/04/26 17:14:35 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_map(t_game *game)
{
	int	i;
	int	lines;
	int	columns;

	i = 0;
	while (game->map[i])
		i++;
	lines = i;
	i = 0;
	columns = ft_strlen(game->map[i]);
	game->win = mlx_new_window(game->mlx, columns * 70, lines * 70, "Game");
}

void	draw(t_game *game)
{
	if (game->n_collect == 0)
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "includes/assets/open.xpm",
				&game->img_w, &game->img_h);
	if (game->map[game->p_x][game->p_y - 1] == 'N'
			|| game->map[game->p_x][game->p_y + 1] == 'N'
			|| game->map[game->p_x - 1][game->p_y] == 'N'
			|| game->map[game->p_x + 1][game->p_y] == 'N')
		tombdraw(game);
	image_drawer(game);
	print_moves(game);
}

void	init_textures(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "includes/assets/hero_right.xpm",
			&game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "includes/assets/wall.xpm", &game->img_w, &game->img_h);
	game->img_backg = mlx_xpm_file_to_image
		(game->mlx, "includes/assets/back.xpm", &game->img_w, &game->img_h);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, "includes/assets/collect.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "includes/assets/close.xpm", &game->img_w, &game->img_h);
	game->img_enemies = mlx_xpm_file_to_image
		(game->mlx, "includes/assets/mid.xpm", &game->img_w, &game->img_h);
	if (!game->img_player || !game->img_wall
		|| !game->img_backg || !game->img_collect
		|| !game->img_enemies || !game->img_exit)
	{
		perror("error with xpm files");
		free_map(game);
		exit(EXIT_FAILURE);
	}
	draw(game);
}

void	image_drawer(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			drawer(game, i, j);
			j++;
		}
		i++;
	}
}

void	drawer(t_game *game, int i, int j)
{
	mlx_put_image_to_window
		(game->mlx, game->win, game->img_backg, j * 70, i * 70);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window
			(game->mlx, game->win, game->img_wall, j * 70, i * 70);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window
			(game->mlx, game->win, game->img_player, j * 70, i * 70);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window
			(game->mlx, game->win, game->img_collect, j * 70, i * 70);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window
			(game->mlx, game->win, game->img_exit, j * 70, i * 70);
	else if (game->map[i][j] == 'N')
		mlx_put_image_to_window
			(game->mlx, game->win, game->img_enemies, j * 70, i * 70);
}
