/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:24:54 by rsiah             #+#    #+#             */
/*   Updated: 2025/05/07 17:13:02 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/controls.h"

int	key_handler(int key, t_game *game)
{
	(void)game;
	if (key == XK_Escape)
		mlx_loop_end(game -> mlx);
	printf("key pressed: %d\n", key);
	return (1);
}