/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_cleanup_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:56:30 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/28 17:56:31 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_array(map -> data);
	free(map -> mapstr);
	map -> mapstr = NULL;
	free(map);
	map = NULL;
}

void	free_tokens(t_queue *queue)
{
	t_tok	*traverse;
	t_tok	*temp;

	if (!queue)
		return ;
	traverse = queue -> tok_head;
	while (traverse)
	{
		temp = traverse;
		traverse = traverse -> next;
		free(temp);
		temp = NULL;
	}
}

/**This frees tokens too */
void	free_queue(t_queue *queue)
{
	t_coord	*traverse;
	t_coord	*temp;

	if (!queue)
		return ;
	traverse = queue -> head;
	while (traverse)
	{
		temp = traverse;
		traverse = traverse -> next;
		free(temp);
		temp = NULL;
	}
	free_tokens(queue);
	free(queue);
	queue = NULL;
}

void	free_image(void *mlx, void *img)
{
	if (img)
	{
		mlx_destroy_image(mlx, img);
		img = NULL;
	}
}
