#include "so_long.h"

void	free_map(t_map *map)
{
	free_array(map -> data);
	free(map -> mapstr);
	free(map);
}
