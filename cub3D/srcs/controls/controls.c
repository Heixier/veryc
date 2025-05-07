/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:24:54 by rsiah             #+#    #+#             */
/*   Updated: 2025/05/07 21:35:20 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/controls.h"

int	key_handler(int key, t_game *game)
{
	game -> key = key;
	if (game -> key == XK_Escape)
		mlx_loop_end(game -> mlx);
	return (1);
}

int	mouse_handler(int button, int x, int y, t_game *game)
{
	game -> mb = button;
	game -> mx = x;
	game -> my = y;
	// printf("mouse: button: %d x: %d y: %d\n", button, x, y);
	return (1);
}