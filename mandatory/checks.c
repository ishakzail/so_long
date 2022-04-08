/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:57:12 by izail             #+#    #+#             */
/*   Updated: 2022/04/06 11:57:14 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_game *game)
{
	int	lines;

	lines = 1;
	while (game->map[lines])
	{
		if (ft_strlen(game->map[0]) != ft_strlen(game->map[lines]))
			return (0);
		lines++;
	}
	return (1);
}

int check_line(t_game *game)
{
	int	i;
	int	j;
	int len;

	i = -1;
	len = ft_strlen(game->map[i+1]);
	while (game->map[++i])
	{
		j = -1;
		while (++j < len)
			if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'E'
			&& game->map[i][j] != 'C' && game->map[i][j] != 'P')
			return (0);
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (game->map[i] != '\0')
		i++;
	while (game->map[0][j] != '\0' && game->map[i - 1][j] != '\0')
	{
		if (game->map[0][j] != '1' || game->map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	len = ft_strlen(game->map[i]) - 1;
	while (game->map[i] != '\0')
	{
		if (game->map[i][0] != '1' || game->map[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}