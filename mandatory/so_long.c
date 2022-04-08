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

void    display_map(t_game *game)
{
    int i;

    i = 0;
    while (game->map[i])
        ft_printf("%s\n",game->map[i++]);
}

void check_map(t_game *game)
{
    if (!map_correct_form(game))
    {
        ft_printf("The map in not in the correct form\n");
        exit(EXIT_FAILURE);
    }
    else if (!check_rectangular(game))
    {
        ft_printf("map is not rectangular\n");
    }
    else if (!check_line(game))
    {
        ft_printf("Map is invalid, it contains another caracters !\n");
    }
    else if (!check_walls(game))
        ft_printf("Error in walls");
    else 
        display_map(game);

            
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
    check_line(&game);
}
