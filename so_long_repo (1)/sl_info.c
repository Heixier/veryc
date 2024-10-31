/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:50:06 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:50:07 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*Print character array*/
void	print_toks(t_queue *queue)
{
	t_tok	*traverse;

	if (!queue | !queue -> tok_head)
		return ;
	traverse = queue -> tok_head;
	ft_printfd(1, "Tokens:\n");
	while (traverse)
	{
		ft_printfd(1, "%c", traverse -> c);
		traverse = traverse -> next;
	}
	ft_printfd(1, "\n");
}

void	print_queue(t_queue *queue)
{
	t_coord	*traverse;
	int		i;

	i = 1;
	if (!queue)
	{
		ft_printfd(1, "Where is your queue?\n");
		return ;
	}
	traverse = queue -> head;
	while (traverse)
	{
		ft_printfd(1, "%d: x: %d | y: %d\n", i, traverse -> x, traverse -> y);
		traverse = traverse -> next;
		i++;
	}
}

void	print_errors(t_merr *errors)
{
	ft_printfd(1, "errors: %d\n", errors -> errors);
	ft_printfd(1, "shape: %d\n", errors -> shape);
	ft_printfd(1, "invalid characters: %d\n", errors -> characters);
	ft_printfd(1, "left_wall: %d\n", errors -> left_wall);
	ft_printfd(1, "right_wall: %d\n", errors -> right_wall);
	ft_printfd(1, "top_wall: %d\n", errors -> top_wall);
	ft_printfd(1, "bottom_wall: %d\n", errors -> bottom_wall);
	ft_printfd(1, "tokens: %d\n", errors -> tokens);
	ft_printfd(1, "exits: %d\n", errors -> exits);
	ft_printfd(1, "players: %d\n", errors -> players);
}

int	print_map(t_map *map)
{
	ft_printfd(1, "Mapstr [%d]: \t\n%s\n", map -> size, map -> mapstr);
	print_array(map -> data, "Array: \n");
	ft_printfd(1, "Width: %d\nHeight: %d\nCollectibles: %d\n\
Exits: %d\nPlayers: %d\n", \
	map -> width, map -> height, map -> tokens, map -> exits, map -> players);
	return (1);
}
