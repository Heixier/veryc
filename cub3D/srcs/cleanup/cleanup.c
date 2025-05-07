/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:01:45 by rsiah             #+#    #+#             */
/*   Updated: 2025/05/07 17:13:36 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	free_mlx(t_game *game)
{
	if (game -> win)
		(mlx_destroy_window(game -> mlx, game -> win), game -> win = NULL);
	if (game -> mlx)
		(mlx_destroy_display(game -> mlx), ft_free((void **)&game -> mlx));
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game -> mlx)
		free_mlx(game);
	ft_free((void **)&game);
	printf("cleanupped\n");
}
