/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:44 by izail             #+#    #+#             */
/*   Updated: 2022/03/29 17:35:46 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_map(t_game *game)
{
    int i;

    i = 0;
    while (game->map[i])
        ft_printf("%s\n",game->map[i++]);
}

void check_map(t_game *game)
{
    if (!map_correct_form(game))
        return (ft_printf("The map in not in the correct form\n"),exit(EXIT_FAILURE));
    else if (!check_rectangular(game))
        return(ft_printf("map is not rectangular\n"),exit(EXIT_FAILURE));
    else if (!check_line(game))
        return (ft_printf("Map is invalid, it contains another caracters !\n"),exit(EXIT_FAILURE));
    else if (!check_walls(game))
        return (ft_printf("Error in walls"), exit(EXIT_FAILURE));
    else if (!check_map_objects(game))
        return (ft_printf(""),exit(EXIT_FAILURE));
    // else 
    //     display_map(game);
            
}

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
int	check_extention(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b'
		&& str[i - 4] == '.')
		return (1);
	return (0);
}

int key_print(int n , t_game *game)
{
    (void ) game;
    ft_printf("%d\n", n);
    return (0);
}

int main(int ac, char **av)
{
    t_game game;
    
    if (ac == 2)
    {
        if (!check_extention(av[1]))
        {
            ft_printf("The extention in invalid");
            return (0);
        }
    }
    else
    {
        ft_printf("Invalid number of argumets");
        return (0);
    }
    game.map = ft_read_map(&game, av[1]);
    check_map(&game);
    // print_map(&game);
    player_position(&game);
    game.mlx = mlx_init();
    display_map(&game);
    init_textures(&game);
    mlx_key_hook(game.win,key_print,&game);
    mlx_loop(game.mlx);
}
