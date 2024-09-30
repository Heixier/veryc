/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:08:03 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/20 15:08:04 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_printfd.h"
#include "libft.h"

int	px_exec_cmd_in(t_px *px, char **cmd)
{
	char	*exe_path;

	exe_path = px_test_cmd(px, cmd);
	if (!exe_path)
		return (px -> err_cmd = cmd[0], ENOENT);
	dup2(px -> in_fd, STDIN_FILENO);
	dup2(px -> pipe_fd[1], STDOUT_FILENO);
	close_px(px);
	execve(exe_path, cmd, px -> envp);
	return (free(exe_path), px -> err_cmd = cmd[0], -1);
}

int	px_exec_cmd_out(t_px *px, char **cmd)
{
	char	*exe_path;

	exe_path = px_test_cmd(px, cmd);
	if (!exe_path)
		return (px -> err_cmd = cmd[0], ENOENT);
	dup2(px -> out_fd, STDOUT_FILENO);
	dup2(px -> pipe_fd[0], STDIN_FILENO);
	close_px(px);
	execve(exe_path, cmd, px -> envp);
	return (free(exe_path), px -> err_cmd = cmd[0], -1);
}

char	*px_test_cmd(t_px *px, char **cmd)
{
	int		i;
	char	*cmd_buffer;

	i = 0;
	if (cmd[0] && access(cmd[0], X_OK) == 0 && !ft_strncmp(cmd[0], "./", 2))
		return (ft_strdup(cmd[0]));
	if (!px -> paths)
		return (NULL);
	while (px -> paths[i])
	{
		cmd_buffer = get_cmd_path(px -> paths[i], cmd[0]);
		if (cmd_buffer)
		{
			if (access(cmd_buffer, X_OK) == 0)
				return (cmd_buffer);
		}
		free(cmd_buffer);
		i++;
	}
	return (NULL);
}

/** Uses malloc to create a path string, + 1 for the "/" char and 1 for NULL*/
char	*get_cmd_path(char *path, char *cmd)
{
	char	*output;
	size_t	len;

	if (!cmd)
		return (NULL);
	len = ft_strlen(path) + ft_strlen(cmd) + 2;
	output = ft_calloc(len, 1);
	ft_strlcat(output, path, len);
	ft_strlcat(output, "/", len);
	ft_strlcat(output, cmd, len);
	return (output);
}

// void	find_executable_path(t_px px, char *cmd)
// {
// 	int		i;
// 	int		path_len;
// 	char	*curr_path;

// 	i = 0;
// 	if (px.paths == NULL)
// 		return (NULL);
// 	while (px.paths[i])
// 	{
// 		curr_path = ft_strlcat(px.paths[i], "/", 
// 		if (access(px.paths[i])
// 	}
// }
