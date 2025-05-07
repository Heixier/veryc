/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:14:22 by rsiah             #+#    #+#             */
/*   Updated: 2025/05/07 21:34:10 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

#include "cub3d.h"

t_game	*init_game(void);
void	init_window(t_game *game);
int		main_loop(t_game *game);
void	display_status(t_game *game);
int		render(t_game *game);

#endif