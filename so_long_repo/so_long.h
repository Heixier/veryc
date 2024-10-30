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

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"
# include "mlx.h"

# define MIN_TOKENS 1
# define IMG_SIZE 16
# define WIN_TITLE "so_tiny"
# define PADDING 32

# define BEFORE 2
# define AFTER 3

# define WALL '1'
# define EMPTY '0'
# define TOKEN 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ALLOWED "10CEP"

# define BG_PATH "./assets/tiles/tile121.xpm"
# define TILE_PATH "./assets/tiles/tile019.xpm"
# define PLAYER_PATH "./assets/weapons/tile385.xpm"
# define TOKEN_PATH "./assets/dogs/tile032.xpm"
# define EXIT_PATH "./assets/tiles/tile035.xpm"

typedef struct s_map
{
	char	**data;
	char	*mapstr;
	int		size;
	int		width;
	int		height;
	int		tokens;
	int		exits;
	int		players;
	int		player_x;
	int		player_y;
}			t_map;

typedef struct s_merr
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

typedef struct s_playr
{
	int	x;
	int	y;
	int	on_exit;
	int	tokens;
}				t_playr;

typedef struct s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;
}				t_coord;

typedef struct s_tok
{
	char			c;
	struct s_tok	*next;
}				t_tok;

typedef struct s_queue
{
	t_coord			*head;
	struct s_queue	*checked;
	t_tok			*tok_head;
}				t_queue;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*bg_img;
	void	*tile_img;
	void	*player_img;
	void	*token_img;
	void	*exit_img;
	t_map	*map;
	t_playr	*player;
	int		tile_size;
}				t_game;

//cleanup
void	free_map(t_map *map);
void	free_tokens(t_queue *queue);
void	free_queue(t_queue *queue);
void	free_mlx(t_game *game);
int		free_game(t_game *game);
void	free_image(void *mlx, void *img);

//utils
int		sl_count_arr(char **array);
int		sl_count_str(char *str, char c);

//map
int		read_map(t_map *map, char	*filename);
void	set_map_size(t_map *map, char *filename);

//read
t_map	*init_map(char *filename);
int		set_map_items(t_map *map, char *filename);

//info
int		print_map(t_map *map);
void	print_toks(t_queue *queue);
void	print_queue(t_queue *queue);
void	print_errors(t_merr *errors);
void	print_array(char **array, char *msg);

//map_errors
void	map_print_errors(t_merr *errors, t_map *map);
int		map_tally_errors(t_merr *errors, t_map *map);
t_merr	*set_errors(t_map *map);
int		validate_map(t_map *map);

//validate_map
void	map_check_shape(t_map *map, t_merr *errors);
void	map_check_walls(t_map *map, t_merr *errors);
void	map_check_items(t_map *map, t_merr *errors);
void	map_check_elements(t_map *map, t_merr *errors);
int		check_if_eof(char *str);
int		check_no_empty_line(char *str);

//validate_path
void	set_player_coords(t_map *map);
int		sl_floodfill(t_map *map, t_queue *queue);
t_queue	*init_queue(void);
int		map_check_path(t_map *map);
int		sl_count_tokens(t_map *map, t_queue *queue);

//path_read
void	checked_add_back(t_queue *checked, int x, int y);
void	lst_append_tok(t_queue *queue, t_map *map, int x, int y);
t_tok	*lst_new_tok(t_map *map, int x, int y);
int		coord_check_valid(t_queue *queue, t_map *map, int x, int y);
int		coord_in_checked(t_queue *checked, int x, int y);

//path utils
t_coord	*lst_new_coord(int x, int y);
void	lst_append_valid_coord(t_queue *queue, t_map *map, int x, int y);
void	lst_pop_coord(t_queue *queue);

//init_game
void	*init_game(t_map *map);
t_playr	*init_player(t_map *map);
int		sl_init_win(t_game *game, t_map *map);
int		init_images(t_game *game);

//run
int		run_game(t_game *game);
void	victory_handler(t_game *game);
int		loop_handler(t_game *game);
int		key_handler(int keycode, t_game *game);
void	render_tile(t_game *game, int x, int y);

//movement
void	move_direction_check(int keycode, t_game *game);
void	move_if_valid(int *target, t_game *game);
void	move_player(int *target, t_game *game);

//render
void	render_frame(t_game *game);
void	render_map(t_game *game);

#endif
