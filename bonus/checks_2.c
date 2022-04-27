/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:33:12 by izail             #+#    #+#             */
/*   Updated: 2022/04/27 15:43:43 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_obj(t_game *game, char c)
{
	int	i;
	int	j;
	int	len;
	int	obj;

	obj = 0;
	i = 1;
	len = ft_strlen(game->map[i]) - 1;
	while (game->map[i])
	{
		j = 1;
		while (j < len)
		{
			if (game->map[i][j] == c)
				obj++;
			j++;
		}
		i++;
	}
	return (obj);
}

int	check_map_objects(t_game *game)
{
	if (!check_obj(game, 'P') && !check_obj(game, 'E') && !check_obj(game, 'C'))
		return (ft_printf("All objects are missing"), 0);
	else if (!check_obj(game, 'E') && !check_obj(game, 'P'))
		return (ft_printf("The exit and the player are missing !"), 0);
	else if (!check_obj(game, 'E') && !check_obj(game, 'C'))
		return (ft_printf("The exit and the collectible are missing !"), 0);
	else if (!check_obj(game, 'P') && !check_obj(game, 'C'))
		return (ft_printf("The player and the collectible are missing !"), 0);
	else if (check_obj(game, 'P') != 1)
		return (ft_printf("The map must contains only one player !"), 0);
	else if (check_obj(game, 'E') != 1)
		return (ft_printf("The map must contains only one exit !"), 0);
	else if (check_obj(game, 'C') < 1)
		return (ft_printf("The map must contains at least one collectible"), 0);
	else if (check_obj(game, 'N') < 1)
		return (ft_printf("The map must contains at least one enemie !"), 0);
	return (1);
}

void	check_map(t_game *game)
{
	if (!map_correct_form(game))
		return (ft_printf("The map in not in the correct form\n"), exit(1));
	else if (!check_rectangular(game))
		return (ft_printf("map is not rectangular\n"), exit(1));
	else if (!check_line(game))
		return (ft_printf("Map invalid, it contains another caracters !\n"),
			exit(1));
	else if (!check_walls(game))
		return (ft_printf("Error in walls"), exit(1));
	else if (!check_map_objects(game))
		return (ft_printf(""), exit(1));
	else if (!check_0(game))
		return (ft_printf(""), exit(1));
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
