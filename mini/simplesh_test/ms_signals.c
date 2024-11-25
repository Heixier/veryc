/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiah <rsiah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:05:07 by rsiah             #+#    #+#             */
/*   Updated: 2024/11/18 17:10:24 by rsiah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

void	sig_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signal == SIGQUIT)
	{
		write(1, "\e[2K", 5);
		rl_on_new_line();
		rl_redisplay();
	}
}

// Assigns SIGINT and SIGQUIT to our custom sighandler function
void	sig_setter(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}