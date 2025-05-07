/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:19:55 by rsiah             #+#    #+#             */
/*   Updated: 2025/05/07 21:37:37 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/display.h"

int	main_loop(t_game *game)
{
	mlx_key_hook(game -> win, key_handler, game);
	mlx_mouse_hook(game -> win, mouse_handler, game);
	mlx_hook(game -> win, 17, 0L, mlx_loop_end, game -> mlx); // close window
	mlx_loop_hook(game -> mlx, render, game);
	display_status(game);
	// Add rendering stuff below
	mlx_loop(game -> mlx);
	return (1);
}

int	render(t_game *game)
{
	display_status(game);
	return (1);
}

void	display_status(t_game *game)
{
	printf ("key: %d\n", game -> key);
	printf("mouse: button: %d x: %d y: %d\n", game -> mb, game -> mx, game -> my);
}
