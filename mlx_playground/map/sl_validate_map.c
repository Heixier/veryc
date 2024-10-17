#include "so_long.h"

static void	check_walls_x(t_map *map, t_merr *errors);
static void	check_walls_x(t_map *map, t_merr *errors);

void	map_check_shape(t_map *map, t_merr *errors)
{
	int	i;

	i = 0;
	while (map -> data[i])
	{
		if (ft_strlen(map -> data[i]) != ft_strlen(map -> data[0]))
			errors -> shape = 1;
		i++;
	}
}


static void	check_walls_x(t_map *map, t_merr *errors)
{
	int	i;

	i = 0;
	while (map -> data[0][i])
	{
		if (map -> data[0][i] != WALL)
			errors -> top_wall++;
		i++;
	}
	i = 0;
	while (map -> data[map -> height - 1][i])
	{
		if (map -> data[map -> height - 1][i] != WALL)
			errors -> bottom_wall++;
		i++;
	}
}

static void	check_walls_x(t_map *map, t_merr *errors)
{
	int	i;

	i = 0;
	while (map -> data[i][0])
	{
		if (map -> data[i][0] != WALL)
			errors -> left_wall++;
		i++;
	}
	while (map -> data[i][map -> width - 1])
	{
		if (map -> data[i][map -> width - 1])
			errors -> left_wall++;
		i++;
	}
}

void	map_check_walls(t_map *map, t_merr *errors)
{
	check_walls_x(map, errors);
	check_walls_y(map, errors);
}

void	map_check_items(t_map *map, t_merr *errors)
{
	if (map -> tokens < MIN_TOKENS)
		errors -> tokens = 1;
	if (map -> exits != 1)
		errors -> exits = 1;
	if (map -> players != 1)
		errors -> players = 1;
}