#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (1);
	map = init_map(argv[1]);
	if (!map)
		return (1);
	print_map(map);
	validate_map(map);
	free_map(map);
	return (0);
}