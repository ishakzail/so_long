/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:21:12 by izail             #+#    #+#             */
/*   Updated: 2022/04/22 14:22:36 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../includes/gnl/get_next_line.h"
# include "../includes/ft_printf/ft_printf.h"
# include <mlx.h>
# include <math.h>

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

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
    void    *img_enemies;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		n_exit;
    int     pos_enemies;
	int		p_x;
	int		p_y;
    int     e_x;
    int     e_y;
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
void	map_init(t_game *game);

/**************** Checks ****************/

int	check_rectangular(t_game *game);
int check_line(t_game *game);
int	check_walls(t_game *game);
int	check_obj(t_game *game, char c);
int	check_map_objects(t_game *game);
int	check_0(t_game *game);

/**************** Draw ****************/

void	display_map(t_game *game);
void	draw(t_game *game);
void	init_textures(t_game *game);
void	image_drawer(t_game *game);
void	drawer(t_game *game, int i, int j);

void    print_moves(t_game *game);

/**************** Move Player ****************/

void    player_position(t_game *game);

int		destroy_window(t_game *game);
void	move_player(t_game *game, int i, int j);
int		m_hook(int key_code, t_game *game);
void	move_a(t_game *game);
void	move_d(t_game *game);
void	move_w(t_game *game);
void	move_s(t_game *game);

void	win(t_game *game);
void	lose();

#endif