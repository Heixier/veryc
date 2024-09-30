/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:06:19 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/23 17:06:21 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"
#include "ft_printfd.h"

/** Closes all open file descriptors and frees px*/
void	free_px(t_px *px)
{
	if (!px)
		return ;
	free_array(px -> paths);
	free_array(px -> cmd1);
	free_array(px -> cmd2);
	close_px(px);
	free(px);
}

/** Closes all open fds in px and sets them to -1*/
void	close_px(t_px *px)
{
	if (px -> pipe_fd[0] != -1)
	{
		close(px -> pipe_fd[0]);
		px -> pipe_fd[0] = -1;
	}
	if (px -> pipe_fd[1] != -1)
	{
		close(px -> pipe_fd[1]);
		px -> pipe_fd[1] = -1;
	}	
	if (px -> in_fd != -1)
	{
		close(px -> in_fd);
		px -> in_fd = -1;
	}
	if (px -> out_fd != -1)
	{
		close(px -> out_fd);
		px -> out_fd = -1;
	}
}

/** Handles according to error code, frees px, and exits
 * This was my unsuccessful attempt at trying to the
 * prints to not overlap
 * 
 * If it gets here at all it means execve failed to take over
*/
int	px_error(int error, t_px *px)
{
	if (error == ENOENT)
		ft_printfd(2, "px: command not found: %s\n", px -> err_cmd);
	if (error == -1)
		ft_printfd(2, "px: could not execute: %s\n", px -> err_cmd);
	return (-1);
}
