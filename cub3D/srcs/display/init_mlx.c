/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:18:28 by rsiah             #+#    #+#             */
/*   Updated: 2025/05/07 21:28:17 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/display.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (NULL);

	game -> mlx = mlx_init();
	if (!game -> mlx)
		return (ft_free((void **)&game), NULL);

	init_window(game);
	if (!game -> win)
		return (ft_free((void **)&game->mlx), ft_free((void **)game), NULL);
	
	return (game);
}

void	init_window(t_game *game)
{
	// temporary; replace or remove after parsing
	game -> win_width = WIDTH;
	game -> win_height = HEIGHT;
	game -> win_title = TITLE;
	game -> win = mlx_new_window(game -> mlx, game -> win_width, \
		game -> win_height, game -> win_title);
}
