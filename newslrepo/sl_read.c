/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:50:27 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:50:27 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map_size(t_map *map, char *filename);
int		read_map(t_map *map, char	*filename);

void	set_map_size(t_map *map, char *filename)
{
	int		bytes_read;
	char	buffer;
	int		count;
	int		map_fd;

	map_fd = open(filename, O_RDONLY);
	if (map_fd == -1)
	{
		(perror(filename), map -> size = -1);
		return ;
	}
	bytes_read = read(map_fd, &buffer, 1);
	if (!bytes_read)
		(ft_printfd(1, "file is empty!\n"), map -> size = 0);
	count = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(map_fd, &buffer, 1);
		count++;
	}
	if (bytes_read == -1)
		(perror("read"), map -> size = -1);
	ft_close(map_fd);
	map -> size = count;
}

/** Sets the data and mapstr variables*/
int	read_map(t_map *map, char *filename)
{
	int		map_fd;
	int		bytes_read;

	bytes_read = 0;
	set_map_size(map, filename);
	if (map -> size <= 0)
		return (0);
	map -> mapstr = malloc(map -> size + 1);
	if (!map -> mapstr)
		return (perror("malloc"), 0);
	map_fd = open(filename, O_RDONLY);
	if (map_fd == -1)
		return (perror(filename), 0);
	bytes_read = read(map_fd, map -> mapstr, map -> size);
	ft_close(map_fd);
	if (bytes_read == -1)
		return (perror("read"), 0);
	map -> mapstr[map -> size] = '\0';
	map -> data = ft_split(map -> mapstr, "\n");
	if (!map -> data)
		return (ft_printfd(2, "failed to create array\n"), 0);
	return (1);
}

t_map	*init_map(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (perror("malloc"), NULL);
	map -> data = NULL;
	map -> mapstr = NULL;
	map -> width = 0;
	map -> height = 0;
	map -> tokens = 0;
	map -> exits = 0;
	map -> players = 0;
	map -> player_x = 0;
	map -> player_y = 0;
	if (!set_map_items(map, filename))
		return (free_map(map), NULL);
	return (map);
}

/** Counts the number of collectibles, exits, and players */
int	set_map_items(t_map *map, char *filename)
{
	if (!read_map(map, filename))
		return (ft_printfd(2, "failed to load map data\n"), 0);
	if (!map -> mapstr || !map -> mapstr[0])
		return (free_map(map), ft_printfd(2, "insufficient map data!\n"), 0);
	map -> tokens = sl_count_str(map -> mapstr, TOKEN);
	map -> exits = sl_count_str(map -> mapstr, EXIT);
	map -> players = sl_count_str(map -> mapstr, PLAYER);
	map -> width = ft_strlen(map -> data[0]);
	map -> height = sl_count_arr(map -> data);
	return (1);
}
