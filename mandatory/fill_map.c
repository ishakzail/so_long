/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 07:23:38 by izail             #+#    #+#             */
/*   Updated: 2022/04/06 07:23:41 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*word_dup(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**map_alloc(t_game *game, char *line)
{
	int	i;
	int	k;

	i = 0;
	k = 1;
	while (line[i])
	{
		if (line[i] == '\n')
			k++;
		i++;
	}
	game->map = (char **)malloc((k + 1) * sizeof(char *));
	if (!game->map)
		return (NULL);
	return (fill_map(line, game));
}

char	**fill_map(char *line, t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i] != '\0')
		{
			game->map[k] = word_dup(line, j, i);
			j = i + 1;
			k++;
		}
		i++;
	}
	
	game->map[k] = word_dup(line, j, i);
	game->map[++k] = 0;
	return (game->map);
}

void	map_init(t_game *game)
{
	game->n_player = 0;
	game->n_collect = check_obj(game, 'C');
	game->n_exit = 0;
	game->map_h = 0;
	game->map_w = 0;
	game->p_x = 0;
	game->p_y = 0;
}