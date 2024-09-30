/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:05:55 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/20 15:05:57 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define SUCCESS 1
# define FAILURE 0

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>

# ifndef PATH
#  define PATH "PATH="
# endif

typedef struct s_px
{
	int		in_fd;
	int		out_fd;
	int		argc;
	int		pids[2];
	int		pipe_fd[2];
	char	**argv;
	char	**envp;
	char	**paths;
	char	*err_cmd;
	char	**cmd1;
	char	**cmd2;
}				t_px;

void	print_array(char **array, char *desc);
void	print_struct(t_px *px);
t_px	*create_px(int argc, char **argv, char **envp);
char	*px_get_path_str(char **envp);
void	px_set_path_tokens(t_px *px);
void	px_set_commands(t_px *px);

int		px_exec_cmd_in(t_px *px, char **cmd);
int		px_exec_cmd_out(t_px *px, char **cmd);
char	*px_test_cmd(t_px *px, char **cmd);
char	*get_cmd_path(char *path, char *cmd);

int		px_open_files(t_px *px);
int		px_in_fork(t_px *px);
int		px_out_fork(t_px *px);

void	free_px(t_px *px);
void	close_px(t_px *px);
int		px_error(int error, t_px *px);

#endif