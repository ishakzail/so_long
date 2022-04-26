/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:16:28 by izail             #+#    #+#             */
/*   Updated: 2022/04/22 14:16:30 by izail            ###   ########.fr       */
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
		(game->mlx, "includes/assets/dragon_mid.xpm", &game->img_w, &game->img_h);
	if (!game->img_player || !game->img_wall
		|| !game->img_backg || !game->img_collect || !game->img_enemies || !game->img_exit)
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

size_t	get_digits(int n)
{
	size_t	i;

	if (n == 0)
		i = 1;
	else
		i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = get_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str_num)
		return (NULL);
	*(str_num + digits) = 0;
	while (digits--)
	{
		*(str_num + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str_num + 0) = '-';
	return (str_num);
}

void    print_moves(t_game *game)
{
    char    *str;

    str = ft_itoa(game->moves);
    mlx_string_put(game->mlx, game->win, 10, 15, 0xFFFF00, "MOVES :");
    mlx_string_put(game->mlx, game->win, 90, 15, 0xFFFF00, str);
    free(str);
}

int	animation(t_game *game)
{
	ft_printf("loop 1== %d\n", game->loop);
	if (game->loop < 1000)
	{
		game->loop++;
		return (0);
	}
	ft_printf("loop 2== %d\n", game->loop);
	game->loop = 0;
	if (game->pos_enemies == 1)
		game->img_enemies = mlx_xpm_file_to_image
			(game->mlx, "includes/assets/dragon_fly.xpm", &game->img_w, &game->img_h);
	else if (game->pos_enemies == 2)
		game->img_enemies = mlx_xpm_file_to_image
			(game->mlx, "includes/assets/dragon_mid.xpm", &game->img_w, &game->img_h);
	else if (game->pos_enemies == 3)
		game->img_enemies = mlx_xpm_file_to_image
			(game->mlx, "includes/assets/dragon_mini.xpm", &game->img_w, &game->img_h);
	else if (game->pos_enemies == 4)
	{
		game->img_enemies = mlx_xpm_file_to_image
			(game->mlx, "includes/assets/dragon_fly.xpm", &game->img_w, &game->img_h);
		game->pos_enemies = 0;
	}
	draw(game);
	game->pos_enemies++;
	return (0);
}