/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:05:56 by rsiah             #+#    #+#             */
/*   Updated: 2024/11/16 18:04:49 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

void	init_custom_builtins(t_simp *simp)
{
	char	**commands;
	t_node	*temp;
	int		i;
	
	i = 0;
	simp -> custom_builtins = malloc(sizeof(t_list));
	if (!simp -> custom_builtins)
		return ;
	commands = ft_split("echo cd pwd export unset env exit", " ");
	while (commands[i])
	{
		temp = ft_lstnew((char *)commands[i]);
		ft_lstadd_back(&simp -> custom_builtins -> head, temp);
		i++;
	}
	printf("Inited builtins: \n");
	ms_print_slist(simp -> custom_builtins);
}

// Use this like execve
void	ms_echo(t_simp *simp, char *path, char **args, char **envp)
{
	int		i;
	char	nl;

	(void)envp;
	(void)path; //???? necessary?
	i = 1;
	nl = '\n';
	if (!ft_strcmp(args[i], "-n"))
	{
		nl = '\0';
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		i++;
	}
	printf("%c", nl);
	simp -> err_code = 0;
}

void	ms_exit(t_simp *simp)
{
	printf("exit\n");
	simp -> running = 0;
}

// void	ms_env(t_simp *simp)
// {
	
// }

void	command_handler(t_simp *simp, char *cmdstr)
{
	char	**cmds;
	t_node	*traverse;
	
	if (!cmdstr)
		return ;
	cmds = ft_split(cmdstr, "\f\n\r\t\v ");
	traverse = simp -> custom_builtins -> head;
	// while (simp -> custom_builtins -> head)
	// {
	// 	traverse = 
	// }
	if (!ft_strcmp(cmds[0], "echo"))
		ms_echo(simp, cmds[0], cmds, simp -> envp);
	else //try and execve from env path but nothing for now
		(printf("invalid argument!\n"), simp -> err_code = 127);
	ft_free_arr((void **)cmds);
}