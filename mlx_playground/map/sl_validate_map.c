#include "so_long.h"

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