/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:21:21 by rsiah             #+#    #+#             */
/*   Updated: 2025/05/07 16:13:31 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	char	*win_title;
}				t_game;

#endif