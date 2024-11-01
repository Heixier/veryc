/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:50:16 by rsiah             #+#    #+#             */
/*   Updated: 2024/10/17 18:50:17 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// save a current position and next/target position
// if the target position is valid, 
// then swap the current player position and 
// fill the previous position with air
// if the target position was a token, then add one token

//x, y
void	move_direction_check(int keycode, t_game *game)
{
	int	target[2];

	target[0] = game -> player -> x;
	target[1] = game -> player -> y;
	if (keycode == 0x0077 || keycode == 0xff52)
		target[1]--;
	else if (keycode == 0x0061 || keycode == 0xff51)
		target[0]--;
	else if (keycode == 0x0073 || keycode == 0xff54)
		target[1]++;
	else if (keycode == 0x0064 || keycode == 0xff53)
		target[0]++;
	else
		return ;
	move_if_valid(target, game);
}

void	move_player(int *target, t_game *game)
{
	char	old_tile;

	old_tile = EMPTY;
	if (game -> player -> on_exit)
	{
		game -> player -> on_exit = 0;
		old_tile = EXIT;
	}
	if (game -> map -> data[target[1]][target[0]] == EXIT)
		game -> player -> on_exit = 1;
	if (game -> map -> data[target[1]][target[0]] == TOKEN)
		game -> player -> tokens++;
	game -> map -> data[target[1]][target[0]] = 'P';
	game -> map -> data[game -> player -> y][game -> player -> x] = old_tile;
	game -> player -> x = target[0];
	game -> player -> y = target[1];
}

/**Technically, just checking for walls is enough
 * because of map validation requirements
*/
void	move_if_valid(int *target, t_game *game)
{
	if (game -> map -> data[target[1]][target[0]] != WALL)
	{
		move_player(target, game);
		game -> moves++;
		ft_printfd(1, "moves:%d\n", game -> moves);
	}
}
