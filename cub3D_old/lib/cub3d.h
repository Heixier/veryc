/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@42singapore.sg>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:36:08 by rsiah             #+#    #+#             */
/*   Updated: 2025/05/07 16:41:17 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H


// TEMPORARY WINDOW DEFINES
# define WIDTH 1280
# define HEIGHT 720
# define TITLE "mapname"

// Keycodes
# define XK_LATIN1
# define XK_MISCELLANY
# include "X11/keysymdef.h"

// Files and memory (open, close, read, write)
# include <fcntl.h>
# include <unistd.h>

// Input and outputs (printf, types)
# include <stdlib.h>
# include <stdio.h>

// Timing and calculations (gettimeofday, maths)
# include <time.h>
# include <math.h>

// Custom libraries
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

// Custom headers
# include "structs.h"
# include "display.h"
# include "cleanup.h"
# include "controls.h"

#endif