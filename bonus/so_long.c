/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:14:32 by izail             #+#    #+#             */
/*   Updated: 2022/04/27 15:44:06 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	win(t_game *game)
{
	ft_printf("Congratulations, you found all the Eggs and the exit.\n");
	ft_printf("You won!\n");
	ft_printf("Is %d moves really the best you can do?\n", game->moves);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		if (!check_extention(av[1]))
			return (ft_printf("The extention is invalid"), 0);
	}
	else
		return (ft_printf("Invalid number of argumets"), 0);
	game.map = ft_read_map(&game, av[1]);
	check_map(&game);
	map_init(&game);
	player_position(&game);
	game.mlx = mlx_init();
	display_map(&game);
	init_textures(&game);
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_hook(game.win, 17, (1L << 2), destroy_window, &game);
	mlx_hook(game.win, 2, (1L << 0), m_hook, &game);
	mlx_loop(game.mlx);
	free_map(&game);
	free(game.mlx);
}
