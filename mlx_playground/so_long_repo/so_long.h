/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:50:49 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:50:51 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "libft.h"

#define MIN_TOKENS 2

#define WALL '1'
#define EMPTY '0'
#define TOKEN 'C'
#define EXIT 'E'
#define PLAYER 'P'
#define ALLOWED "10CEP"

typedef	struct s_map
{
	char	**data;
	char	*mapstr;
	int		size;
	int		width;
	int		height;
	int		tokens;
	int		exits;
	int		players;
}			t_map;

typedef	struct	s_merr
{
	int	errors;
	int	shape;
	int	left_wall;
	int	right_wall;
	int	top_wall;
	int	bottom_wall;
	int	characters;
	int	tokens;
	int	exits;
	int	players;
	int	path;
}				t_merr;

typedef struct	s_game
{
	int	player_x;
	int	player_y;
}				t_game;

typedef struct	s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;
}				t_coord;

typedef struct	s_queue
{
	t_coord	*head;
}				t_queue;

typedef struct	s_tok
{
	char			c;
	struct s_tok	*next;
}				t_tok;

typedef struct	s_tokq
{
	t_tok	*head;
}				t_tokq;

//cleanup
void	free_map(t_map *map);

//utils
int		sl_count_arr(char **array);
int		sl_count_str(char *str, char c);

//map
t_map	*init_map(char *name);
int		read_map(t_map *map, char	*filename);
void	set_map_size(t_map *map, char *filename);
int		set_map_items(t_map *map, char *filename);

//read
t_map	*init_map(char *filename);
int		set_map_items(t_map *map, char *filename);

//info
void	print_map(t_map *map);
void	print_array(char **array, char *msg);

//map_errors
void	map_print_errors(t_merr *errors);
int		map_tally_errors(t_merr *errors);
t_merr	*set_errors(t_map *map);
int		validate_map(t_map *map);

//validate_map
void	map_check_shape(t_map *map, t_merr *errors);
void	map_check_walls(t_map *map, t_merr *errors);
void	map_check_items(t_map *map, t_merr *errors);
void	map_check_elements(t_map *map, t_merr *errors);

//validate_path
int	map_check_path(t_map *map, t_game *game);

#endif
