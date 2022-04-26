/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:57:44 by izail             #+#    #+#             */
/*   Updated: 2022/04/26 17:12:17 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	print_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 10, 15, 0xFFFF00, "MOVES :");
	mlx_string_put(game->mlx, game->win, 90, 15, 0xFFFF00, str);
	free(str);
}

int	animation(t_game *game)
{
	if (game->loop < 1000)
	{
		game->loop++;
		return (0);
	}
	game->loop = 0;
	mlx_destroy_image(game->mlx, game->img_enemies);
	if (game->pos_enemies == 1)
		game->img_enemies = mlx_xpm_file_to_image
			(game->mlx, "includes/assets/fly.xpm", &game->img_w, &game->img_h);
	else if (game->pos_enemies == 2)
		game->img_enemies = mlx_xpm_file_to_image
			(game->mlx, "includes/assets/mid.xpm", &game->img_w, &game->img_h);
	else if (game->pos_enemies == 3)
		game->img_enemies = mlx_xpm_file_to_image
			(game->mlx, "includes/assets/mini.xpm", &game->img_w, &game->img_h);
	else if (game->pos_enemies == 4)
	{
		game->img_enemies = mlx_xpm_file_to_image
			(game->mlx, "includes/assets/fly.xpm", &game->img_w, &game->img_h);
		game->pos_enemies = 0;
	}
	draw(game);
	game->pos_enemies++;
	return (0);
}

void	tombdraw(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "includes/assets/tomb.xpm", &game->img_w, &game->img_h);
}
