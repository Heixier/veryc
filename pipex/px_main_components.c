/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main_components.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:30:43 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/26 14:30:44 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printfd.h"
#include "libft.h"

int	px_open_files(t_px *px)
{
	px -> in_fd = open(px -> argv[1], O_RDONLY);
	if (px -> in_fd == -1)
		perror("px: infile");
	px -> out_fd = open(px -> argv[px -> argc -1], \
	O_RDWR | O_CREAT | O_TRUNC, 420);
	if (px -> out_fd == -1)
		return (-1);
	return (1);
}

int	px_in_fork(t_px *px)
{
	px -> pids[0] = fork();
	if (px -> pids[0] == -1)
		return (perror("px: fork"), -1);
	if (px -> pids[0] == 0)
	{
		if (px -> in_fd != -1)
			return (px_error(px_exec_cmd_in(px, px -> cmd1), px));
		return (-1);
	}
	return (1);
}

int	px_out_fork(t_px *px)
{
	px -> pids[1] = fork();
	if (px -> pids[1] == -1)
		return (wait(NULL), perror("px: fork"), -1);
	if (px -> pids[1] == 0)
		return (px_error(px_exec_cmd_out(px, px -> cmd2), px));
	return (1);
}
