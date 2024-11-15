/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:05:56 by rsiah             #+#    #+#             */
/*   Updated: 2024/11/15 18:35:04 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

void	ms_echo(t_simp *simp, char *cmd)
{
	if (!strncmp(&cmd[5], "-n ", 3))
		printf("%s", &cmd[8]); // "echo -n " = 8
	else
		printf("%s\n", &cmd[5]); // "echo " = 5
	simp -> err_code = 0;
}

void	ms_exit(t_simp *simp)
{
	printf("exit\n");
	simp -> running = 0;
}

void	ms_env(t_simp *simp)
{
	
}

void	command_handler(t_simp *simp, char *cmd)
{
	if (!ft_strncmp(cmd, "echo ", 5))
		ms_echo(simp, cmd);
	if (!ft_strcmp(cmd, "exit")) // need parsing, case "exit      "
		ms_exit(simp);
	if (!ft_strcmp(cmd, "env")) // also need parsing, same case
		ms_env(simp);
		
}