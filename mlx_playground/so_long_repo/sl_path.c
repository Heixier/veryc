/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:50:21 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:50:23 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Creates a new coordinate struct*/
t_coord	*lst_new_coord(int x, int y)
{
	t_coord	*coord;
	
	coord = malloc(sizeof(t_coord));
	// if (!coord)
	// 	return (ft_printfd(2, "Malloc failed\n"), NULL);
	coord -> x = x;
	coord -> y = y;
	coord -> next = NULL;
	return (coord);
}

void	lst_append_coord(t_queue *queue, int x, int y)
{
	t_coord	*coord;
	t_coord	*traverse;

	coord = lst_new_coord(x, y);
	traverse = queue -> head;
	while (traverse -> next)
		traverse = traverse -> next;
	traverse -> next = coord;
}

/* Set up the queue for our bfs algorithm*/
int	map_check_path(t_map *map, t_game *game)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	// if (!queue)
	// 	return (ft_printfd(2, "Malloc failed\n"), 0);
	queue -> head = lst_new_coord(game -> player_x, game -> player_y);
	if (!queue -> head)
		return (0);
}

#include <stdio.h>

void	print_list(t_queue *queue)
{
	t_coord	*traverse;
	int		i;

	i = 1;
	if (!queue)
	{
		printf("Where is your queue?\n");
		return ;
	}
	traverse = queue -> head;
	while (traverse)
	{
		printf("%d: x: %d | y: %d\n", i, traverse -> x, traverse -> y);
		traverse = traverse -> next;
	}
}

int main(void)
{
	t_queue	*queue;???? where maloc

	queue -> head = lst_new_coord(3, 5);
	lst_append_coord(queue, 8, 2);
	print_list(queue);
	return (0);
}
