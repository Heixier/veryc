/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:28:29 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/28 17:28:30 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_frame(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game -> map -> data[y])
	{
		x = 0;
		while (game -> map -> data[y][x])
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
