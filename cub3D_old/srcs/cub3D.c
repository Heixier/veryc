/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:34:54 by rsiah             #+#    #+#             */
/*   Updated: 2025/05/07 21:28:36 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int main(int argc, char **argv)
{
	t_game	*game;

	if (!argc && !argv)
		return (0);
	game = init_game();
	if (!game)
		return (1);
	main_loop(game);

	free_game(game);
	printf ("done\n");
}
