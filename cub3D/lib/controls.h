/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:25:17 by rsiah             #+#    #+#             */
/*   Updated: 2025/05/07 21:27:42 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

#include "cub3d.h"

int	key_handler(int key, t_game *game);
int	mouse_handler(int button, int x, int y, t_game *game);

#endif