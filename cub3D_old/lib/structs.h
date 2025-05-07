/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:21:21 by rsiah             #+#    #+#             */
/*   Updated: 2025/05/07 21:31:15 by rsiah            ###   ########.fr       */
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
	int		mb;
	int		mx;
	int		my;
	int		key;
}				t_game;

#endif