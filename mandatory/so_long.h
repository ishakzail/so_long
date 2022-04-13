/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:35:54 by izail             #+#    #+#             */
/*   Updated: 2022/03/29 17:35:57 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../includes/gnl/get_next_line.h"
# include "../includes/ft_printf/ft_printf.h"
# include <mlx.h>
# include <math.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		p_x;
	int		p_y;
	int		moves;
}	t_game;

char    **ft_read_map(t_game *game, char *path);
int		map_correct_form(t_game *game);
char	*check(char *line, char *holder);
void	ft_free(char *line, char *holder);
char	**fill_map(char *line, t_game *game);
char	**map_alloc(t_game *game, char *line);
char	*word_dup(char *str, int start, int finish);

void	free_map(t_game *game);

/**************** Checks ****************/

int		check_rectangular(t_game *game);
int 	check_line(t_game *game);
int		check_walls(t_game *game);
int		check_obj(t_game *game, char c);
int		check_map_objects(t_game *game);

/**************** Draw ****************/

void	display_map(t_game *game);
void	draw(t_game *game);
void	init_textures(t_game *game);
void	image_drawer(t_game *game);
void	drawer(t_game *game, int i, int j);
#endif