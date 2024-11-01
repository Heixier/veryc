/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:30:03 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/22 15:30:05 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*Creates a new coordinate struct*/
t_coord	*lst_new_coord(int x, int y)
{
	t_coord	*coord;

	coord = malloc(sizeof(t_coord));
	if (!coord)
		return (ft_printfd(2, "Malloc failed\n"), NULL);
	coord -> x = x;
	coord -> y = y;
	coord -> next = NULL;
	return (coord);
}

/*Appends valid coordinates to the queue as well as 
building up the checked coord list */
void	lst_append_valid_coord(t_queue *queue, t_map *map, int x, int y)
{
	t_coord	*coord;
	t_coord	*traverse;

	if (!coord_check_valid(queue, map, x, y))
		return ;
	coord = lst_new_coord(x, y);
	if (!coord)
		return ;
	if (!queue -> head)
	{
		queue -> head = coord;
		return ;
	}
	traverse = queue -> head;
	while (traverse -> next)
		traverse = traverse -> next;
	lst_append_tok(queue, map, x, y);
	traverse -> next = coord;
}

/*Removes a coordinate from the top of the queue*/
void	lst_pop_coord(t_queue *queue)
{
	t_coord	*output;

	if (!queue | !queue -> head)
		return ;
	output = queue -> head;
	queue -> head = queue -> head -> next;
	free(output);
	output = NULL;
}
