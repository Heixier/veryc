#include "so_long.h"

void	map_print_errors(t_merr *errors)
{
	if (!errors -> errors)
		ft_printfd(1, "no errors found\n");
	else
	{	
		ft_printfd(2, "%d errors found!\n", errors -> errors);
		if (errors -> shape)
			ft_printfd(2, "map not rectangular!\n");
		if (errors -> left_wall)
			ft_printfd(2, "left wall broken!\n");
		if (errors -> right_wall)
			ft_printfd(2, "right wall broken!\n");
		if (errors -> top_wall)
			ft_printfd(2, "top wall broken!\n");
		if (errors -> bottom_wall)
			ft_printfd(2, "bottom wall broken!\n");
		if (errors -> tokens)
			ft_printfd(2, "invalid collectibles: %d\n", errors -> tokens);
		if (errors -> exits)
			ft_printfd(2, "invalid exits: %d\n", errors -> exits);
		if (errors -> players)
			ft_printfd(2, "invalid players: %d\n", errors -> players);
	}
}

/** Returns number of errors found */
int	map_tally_errors(t_merr *errors)
{
	if (errors -> shape)
		errors -> errors++;
	if (errors -> left_wall)
		errors -> errors++;
	if (errors -> right_wall)
		errors -> errors++;
	if (errors -> top_wall)
		errors -> errors++;
	if (errors -> bottom_wall)
		errors -> errors++;
	if (errors -> tokens)
		errors -> errors++;
	if (errors -> exits)
		errors -> errors++;
	if (errors -> players)
		errors -> errors++;
	return (map_print_errors(errors), errors -> errors);
}

void	print_errors(t_merr *errors)
{
	ft_printfd(1, "errors: %d\n", errors -> errors);
	ft_printfd(1, "shape: %d\n", errors -> shape);
	ft_printfd(1, "left_wall: %d\n", errors -> left_wall);
	ft_printfd(1, "right_wall: %d\n", errors -> right_wall);
	ft_printfd(1, "top_wall: %d\n", errors -> top_wall);
	ft_printfd(1, "bottom_wall: %d\n", errors -> bottom_wall);
	ft_printfd(1, "tokens: %d\n", errors -> tokens);
	ft_printfd(1, "exits: %d\n", errors -> exits);
	ft_printfd(1, "players: %d\n", errors -> players);
	ft_printfd(1, "path: %d\n", errors -> path);

}

t_merr	*set_errors(t_map *map)
{
	t_merr	*errors;
	
	errors = ft_calloc(sizeof(t_merr), 1);
	if (!errors)
		return (NULL);
	print_errors(errors);
	if (!map)
		return (NULL);
	// map_check_shape(map, errors);
	// map_check_walls(map, errors);
	// map_check_items(map, errors);
	//map_check_path
	return (errors);
}

int	validate_map(t_map *map)
{
	t_merr	*errors;

	errors = set_errors(map);
	if (!errors)
		return (ft_printfd(2, "Failed to create t_error\n"), 0);
	if (map_tally_errors(errors) > 0)
		return (free(errors), 0);
	return (free(errors), 1);
}