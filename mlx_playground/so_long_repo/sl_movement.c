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

save a current position and next/target position
if the target position is valid, then swap the current player position and fill the previous position with air
if the target position was a token, then add one token

use scanf lolls nvm just mlx hook
