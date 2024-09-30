/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_init_px.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:33:04 by rsiah             #+#    #+#             */
/*   Updated: 2024/09/22 15:33:05 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printfd.h"
#include "pipex.h"

/** Create a px struct and initialises it with the starting values*/
t_px	*create_px(int argc, char **argv, char **envp)
{
	t_px	*px;

	px = malloc(sizeof(t_px));
	if (!px)
		return (perror("malloc"), NULL);
	px -> argc = argc;
	px -> argv = argv;
	px -> envp = envp;
	px_set_path_tokens(px);
	px_set_commands(px);
	px -> in_fd = 0;
	px -> out_fd = 1;
	px -> pids[0] = -1;
	px -> pids[1] = -1;
	px -> err_cmd = NULL;
	return (px);
}

void	px_set_path_tokens(t_px *px)
{
	if (!px_get_path_str(px -> envp))
		px -> paths = NULL;
	else
		px -> paths = ft_split(&((px_get_path_str(px -> envp))[5]), ":");
}

char	*px_get_path_str(char **envp)
{
	int	i;

	i = 0;
	while (envp[i++])
		if (rz_strxcmp(PATH, envp[i], 5) == 0)
			return (envp[i]);
	return (NULL);
}

void	px_set_commands(t_px *px)
{
	px -> cmd1 = ft_split(px -> argv[2], " \t\n\n\v\f\r");
	px -> cmd2 = ft_split(px -> argv[3], " \t\n\n\v\f\r");
}
