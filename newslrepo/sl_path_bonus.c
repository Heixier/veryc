/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:50:21 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:50:23 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_player_coords(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map -> data[y])
	{
		x = 0;
		while (map -> data[y][x])
		{
			if (map -> data[y][x] == PLAYER)
			{
				map -> player_x = x;
				map -> player_y = y;
			}
			x++;
		}
		y++;
	}
}

int	sl_floodfill(t_map *map, t_queue *queue)
{
	t_coord	*current;

	while (queue -> head)
	{
		current = queue -> head;
		lst_append_valid_coord(queue, map, current -> x + 1, current -> y);
		lst_append_valid_coord(queue, map, current -> x - 1, current -> y);
		lst_append_valid_coord(queue, map, current -> x, current -> y + 1);
		lst_append_valid_coord(queue, map, current -> x, current -> y - 1);
		lst_pop_coord(queue);
	}
	return (1);
}

t_queue	*init_queue(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue -> checked = malloc(sizeof(t_queue));
	if (!queue -> checked)
		return (free(queue), NULL);
	queue -> head = NULL;
	queue -> tok_head = NULL;
	queue -> checked -> head = NULL;
	queue -> checked -> checked = NULL;
	queue -> checked -> tok_head = NULL;
	return (queue);
}

int	sl_count_tokens(t_map *map, t_queue *queue)
{
	int		toks;
	int		exits;
	t_tok	*traverse;

	toks = 0;
	exits = 0;
	traverse = queue -> tok_head;
	while (traverse)
	{
		if (traverse -> c == TOKEN)
			toks++;
		if (traverse -> c == EXIT)
			exits++;
		traverse = traverse -> next;
	}
	if (exits != map -> exits)
		return (ft_printfd(2, "No valid path to exit!\n"), 0);
	if (toks != map -> tokens)
		return (ft_printfd(2, "%d tokens unreachable\n", map->tokens - toks), 0);
	return (1);
}

/* Set up the queue for our bfs algorithm*/
int	map_check_path(t_map *map)
{
	t_queue	*queue;

	queue = init_queue();
	if (!queue)
		return (ft_printfd(2, "Malloc fail\n"), 0);
	set_player_coords(map);
	queue -> head = lst_new_coord(map -> player_x, map -> player_y);
	if (!queue -> head)
		return (free_queue(queue -> checked), free_queue(queue), 0);
	sl_floodfill(map, queue);
	if (!sl_count_tokens(map, queue))
		return (free_queue(queue -> checked), free_queue(queue), 0);
	free_queue(queue -> checked);
	free_queue(queue);
	return (1);
}
