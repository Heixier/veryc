/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_path_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:58:25 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/23 18:58:26 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tok	*lst_new_tok(t_map *map, int x, int y)
{
	t_tok	*tok;

	tok = malloc(sizeof(t_tok));
	if (!tok)
		return (NULL);
	tok -> c = map -> data[y][x];
	tok -> next = NULL;
	return (tok);
}

void	lst_append_tok(t_queue *queue, t_map *map, int x, int y)
{
	t_tok	*traverse;
	t_tok	*tok;

	tok = lst_new_tok(map, x, y);
	if (!queue -> tok_head)
		queue -> tok_head = tok;
	else
	{
		traverse = queue -> tok_head;
		while (traverse -> next)
			traverse = traverse -> next;
		traverse -> next = tok;
	}
}

void	checked_add_back(t_queue *checked, int x, int y)
{
	t_coord	*traverse;

	traverse = checked -> head;
	if (!checked -> head)
		checked -> head = lst_new_coord(x, y);
	else
	{
		while (traverse -> next)
			traverse = traverse -> next;
		traverse -> next = lst_new_coord(x, y);
	}
}

int	coord_in_checked(t_queue *checked, int x, int y)
{
	t_coord	*traverse;

	traverse = checked -> head;
	while (traverse)
	{
		if (traverse -> x == x && traverse -> y == y)
			return (1);
		traverse = traverse -> next;
	}
	return (0);
}

int	coord_check_valid(t_queue *queue, t_map *map, int x, int y)
{
	if (x >= map -> width | y >= map -> height)
		return (0);
	if (map -> data[y][x] == WALL)
		return (0);
	if (coord_in_checked(queue -> checked, x, y))
		return (0);
	checked_add_back(queue -> checked, x, y);
	return (1);
}
