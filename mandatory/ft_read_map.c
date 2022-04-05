/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:38:31 by izail             #+#    #+#             */
/*   Updated: 2022/04/05 15:38:33 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **ft_read_map(t_game *game, char *path)
{
    int		fd;
	char	*line;
	char	*holder_map;
	char	*holder;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	holder = ft_strdup("");
	line = get_next_line(fd);
	holder_map = check(line, holder);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		ft_free(line, holder);
	}
    game->map = map_allo(game, holder_map);
    free(holder_map);
    close(fd);
	return (game->map);
}

int	map_correct_form(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != '\0')
		i++;
	if (i < 3)
		return (ft_printf("the map is invalid!!"), 0);
	return (1);
}

char	*check(char *line, char *holder)
{
	char	*str;

	if (!line || *line != '1')
	{
		ft_printf("invalid map!!");
		free(line);
		free(holder);
		exit(EXIT_FAILURE);
	}
	return (str = ft_strjoin(holder, line), free(line), free(holder), str);
}

void	ft_free(char *line, char *holder)
{
	free(line);
	free(holder);
}