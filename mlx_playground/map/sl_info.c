#include "so_long.h"

void	print_array(char **array, char *msg)
{
	int	i;

	i = 0;
	if (array)
	{
		ft_printfd(1, "%s", msg);
		while (array[i])
		{
			ft_printfd(1, "%d: %s\n", i, array[i]);
			i++;
		}
	}
}

void	print_map(t_map *map)
{
	ft_printfd(1, "Mapstr [%d]: \t\n%s\n\n", map -> size, map -> mapstr);
	print_array(map -> data, "Array: \n");
	printf("Width: %d\nHeight: %d\nCollectibles: %d\nExits: %d\nPlayers: %d\n", \
	map -> width, map -> height, map -> tokens, map -> exits, map -> players);
}