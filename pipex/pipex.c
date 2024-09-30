/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:05:38 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/20 15:05:39 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printfd.h"
#include "libft.h"

/** ./pipex file1 cmd1 cmd2 file2*/
int	main(int argc, char **argv, char **envp)
{
	t_px	*px;

	if (argc != 5)
		return (ft_printfd(2, "px: usage: file1 cmd1 cmd2 file2\n", -1));
	px = create_px(argc, argv, envp);
	if (pipe(px -> pipe_fd) == -1)
		return (free_px(px), perror("px: pipe"), -1);
	if (!px)
		return (ft_printfd(2, "px: px_struct failed"), -1);
	if (px_open_files(px) == -1)
		return (free_px(px), perror("px: out"), -1);
	if (px_in_fork(px) == -1)
		return (free_px(px), -1);
	if (px_out_fork(px) == -1)
		return (free_px(px), -1);
	close_px(px);
	waitpid(px -> pids[0], NULL, 0);
	waitpid(px -> pids[1], NULL, 0);
	free_px(px);
	return (0);
}
